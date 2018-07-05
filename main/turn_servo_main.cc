#include "dynamixel_sdk_linux/dynamixel.h"

#include <cstddef>
#include <iostream>

// Abseil common libraries.
#include "absl/strings/str_cat.h"
#include "absl/strings/string_view.h"

// This represents the device (/dev/ttyACM<port>).
// So 0 means the actuator is at /dev/ttyACM0.
constexpr int kDefaultPortnum = 0;

// 1 mbps.
constexpr int kDefaultBaudnum = 1;

int main(int argc, const char *argv[]) {
  // Open device.
  if (dxl_initialize(kDefaultPortnum, kDefaultBaudnum) == 0) {
    printf("Failed to open USB2Dynamixel!\n");
    return 0;
  } else {
    printf("Successfully opened USB2Dynamixel!\n");
  }

  // Devices can be at addresses 0-252. 254 is the broadcast address; sending a
  // message to 254 issues the instruction to all devices.
  //
  // // Set goal speed
  // dxl_write_word(BROADCAST_ID, /*goal_speed=*/32, 0);
  // // Set goal position
  // dxl_write_word(BROADCAST_ID, /*goal_position=*/30, 512);

  dxl_terminate();
  return 0;
}
