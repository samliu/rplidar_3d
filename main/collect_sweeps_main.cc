// Grab frames using RPLidar's SDK.
//
// Original Author: Sam Liu <sam@ambushnetworks.com>

#include <cstddef>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

// RPLIDAR standard sdk headers.
#include "rplidar_lib/rplidar.c"
#include "rplidar_lib/rplidar_driver.h"

// Abseil common libraries.
#include "absl/strings/str_cat.h"
#include "absl/strings/string_view.h"
#include "absl/time/clock.h"
#include "absl/time/time.h"

// Protocol buffers.
#include "main/proto/lidar_scan.pb.h"

#include "util/commandlineflags.h"

DEFINE_uint32(baud_rate, 115200,
              "Baud rate of the RPLidar A2. Refer to datasheet for details.");
DEFINE_string(device_location, "/dev/ttyUSB0",
              "Device location (com path). Example: `/dev/ttyUSB0`.");

#ifndef _countof
#define _countof(_Array) (int)(sizeof(_Array) / sizeof(_Array[0]))
#endif

#ifdef _WIN32
#include <Windows.h>
#define delay(x) ::Sleep(x)
#else
#include <unistd.h>
static inline void delay(_word_size_t ms) {
  while (ms >= 1000) {
    usleep(1000 * 1000);
    ms -= 1000;
  };
  if (ms != 0)
    usleep(ms * 1000);
}
#endif

using namespace rp::standalone::rplidar;

namespace {

u_result collect_spin(RPlidarDriver *driver) {
  u_result ans;

  // Allocate enough space for up to 720 measurements over the course of the 360
  // laser spin. In practice we get about 540-570 total measurements.
  rplidar_response_measurement_node_t nodes[360 * 2];
  size_t count = _countof(nodes);

  // Fetch exactly one 0-360 degrees' scan.
  ans = driver->grabScanData(nodes, count);
  if (IS_OK(ans) || ans == RESULT_OPERATION_TIMEOUT) {
    driver->ascendScanData(nodes, count);

    // Iterate over the nodes, printing each measurement.
    for (int pos = 0; pos < (int)count; ++pos) {
      // AND with bitmask to tell if the measurement was synced.
      std::string sync_string = " ";
      if (nodes[pos].sync_quality & RPLIDAR_RESP_MEASUREMENT_SYNCBIT) {
        sync_string = "S ";
      }
      double theta = (nodes[pos].angle_q6_checkbit >>
                      RPLIDAR_RESP_MEASUREMENT_ANGLE_SHIFT) /
                     64.0f;
      double distance = nodes[pos].distance_q2 / 4.0f;
      std::string nowtime_micros =
          absl::StrCat(absl::ToUnixMicros(absl::Now()));

      // Collect scan data into protobuf.
      rplidar_3d::main::LidarScanPoint scan_point;
      scan_point.set_timestamp_micros(absl::ToUnixMicros(absl::Now()));
      scan_point.set_angle_degrees(theta);
      scan_point.set_distance_meters(distance / 100.0f);

      // Print the results.
      // TODO(samcliu): Add each point to a LidarScanFrame proto. Write these
      // results to a file.
      std::cout << scan_point.DebugString() << std::endl;
    }
  } else {
    printf("error code: %x\n", ans);
  }

  return ans;
}
} // namespace

int main(int argc, char *argv[]) {
  // Parse flags and clear argc/arv.
  gflags::SetUsageMessage("Retrieves lidar scans from the RPLidar A2. Remember "
                          "to use `sudo` to run this if you run into issues "
                          "accessing your device.");
  gflags::ParseCommandLineFlags(&argc, &argv, /*remove_flags=*/true);

  const char *opt_com_path = FLAGS_device_location.c_str();
  _u32 opt_com_baudrate = FLAGS_baud_rate;
  u_result op_result;

  // Create the driver instance.
  RPlidarDriver *driver =
      RPlidarDriver::CreateDriver(RPlidarDriver::DRIVER_TYPE_SERIALPORT);
  if (!driver) {
    fprintf(stderr, "insufficent memory, exit\n");
    exit(-2);
  }

  bool run_loop = true;
  while (run_loop) {
    if (IS_FAIL(driver->connect(opt_com_path, opt_com_baudrate))) {
      fprintf(stderr, "Error, cannot bind to the specified serial port %s.\n",
              opt_com_path);
      break;
    }

    // Get device health and abort the loop if unhealthy.
    rplidar_response_device_health_t healthinfo;
    op_result = driver->getHealth(healthinfo);
    if (IS_OK(op_result)) {
      switch (healthinfo.status) {
      case RPLIDAR_STATUS_OK:
        break;
      case RPLIDAR_STATUS_WARNING:
        printf("RPLidar Health status returned warning!");
        printf(" (errorcode: %d)\n", healthinfo.error_code);
        break;
      case RPLIDAR_STATUS_ERROR:
        printf("RPLidar Health status returned error!");
        printf(" (errorcode: %d)\n", healthinfo.error_code);
        break;
      }
    } else {
      fprintf(stderr, "Error, cannot retrieve the lidar health code: %x\n",
              op_result);
      break;
    }

    if (healthinfo.status == RPLIDAR_STATUS_ERROR) {
      fprintf(stderr, "Error, rplidar internal error detected. Please reboot "
                      "the device to retry.\n");
      // Enable the following if you want rplidar to be rebooted by software:
      // driver->reset();
      break;
    }

    driver->startMotor();

    // Take one 360 deg scan.
    //
    // You can force RPLidar to perform the scan operation regardless of
    // whether the motor is rotating.
    if (IS_FAIL(driver->startScan(/*force=*/false,
                                  /*autoExpressMode=*/true))) {
      fprintf(stderr, "Error, cannot start the scan operation.\n");
      break;
    }

    if (IS_FAIL(collect_spin(driver))) {
      fprintf(stderr, "Error, cannot grab scan data.\n");
      break;
    }

    // TODO(samcliu): Remove after debugging. Limit to 1 run.
    run_loop = false;
  }

  driver->stop();
  driver->stopMotor();

  RPlidarDriver::DisposeDriver(driver);
  return 0;
}
