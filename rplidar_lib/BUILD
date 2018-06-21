# BUILD rules for RPLidar A1 SDK.
package(default_visibility = ["//visibility:public"])

cc_library(
    name = "rplidar",
    hdrs = ["rplidar.c"],
    copts = ["-std=c99"],
    deps = [
        ":rplidar_cmd",
        ":rplidar_protocol",
        ":rptypes",
    ],
)

cc_library(
    name = "rplidar_cmd",
    hdrs = ["rplidar_cmd.c"],
    copts = ["-std=c99"],
    deps = [":rplidar_protocol"],
)

cc_library(
    name = "rplidar_driver",
    srcs = ["rplidar_driver.cc"],
    hdrs = [
        "rplidar_driver.h",
        "rplidar_driver_serial.h",
    ],
    linkopts = ["-lpthread"],  # Link PThread library.
    deps = [
        ":rplidar_cmd",
        ":sdkcommon",
        "//rplidar_lib/hal:abs_rxtx",
        "//rplidar_lib/hal:event",
        "//rplidar_lib/hal:locker",
        "//rplidar_lib/hal:thread",
    ],
)

cc_library(
    name = "rplidar_protocol",
    hdrs = ["rplidar_protocol.c"],
    copts = ["-std=c99"],
)

cc_library(
    name = "rptypes",
    hdrs = ["rptypes.c"],
    copts = ["-std=c99"],
)

cc_library(
    name = "sdkcommon",
    hdrs = [
        "sdkcommon.c",
    ],
    copts = ["-std=c99"],
    deps = [
        "//rplidar_lib/arch/linux:arch_linux",
        "//rplidar_lib/arch/linux:net_serial",
        "//rplidar_lib/arch/linux:timer",
        # "rplidar_lib/arch/macOS:arch_macOS",
        # "rplidar_lib/arch/win32:arch_win32",
        "//rplidar_lib/hal:util",
    ],
)
