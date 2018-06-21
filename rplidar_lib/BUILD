# BUILD rules for RPLidar A1 SDK.
package(default_visibility = ["//visibility:public"])

# All includes accounted for.
cc_library(
    name = "rplidar",
    hdrs = ["rplidar.h"],
    deps = [
        ":rplidar_cmd",
        ":rplidar_protocol",
        ":rptypes",
    ],
)

# All includes accounted for.
cc_library(
    name = "rplidar_cmd",
    hdrs = ["rplidar_cmd.h"],
    deps = [":rplidar_protocol"],
)

# All includes accounted for.
cc_library(
    name = "rplidar_driver",
    srcs = ["rplidar_driver.cc"],
    hdrs = [
        "rplidar_driver.h",
        "rplidar_driver_serial.h",
    ],
    deps = [
        ":rplidar_cmd",
        ":sdkcommon",
        "//rplidar_lib/hal:abs_rxtx",
        "//rplidar_lib/hal:event",
        "//rplidar_lib/hal:locker",
        "//rplidar_lib/hal:thread",
    ],
)

# All includes accounted for.
cc_library(
    name = "rplidar_protocol",
    hdrs = ["rplidar_protocol.h"],
)

# All includes accounted for.
cc_library(
    name = "rptypes",
    hdrs = ["rptypes.h"],
)

# All includes accounted for.
cc_library(
    name = "sdkcommon",
    hdrs = [
        "sdkcommon.h",
    ],
    deps = [
        "//rplidar_lib/arch/linux:arch_linux",
        "//rplidar_lib/arch/linux:timer",
        # "rplidar_lib/arch/macOS:arch_macOS",
        # "rplidar_lib/arch/win32:arch_win32",
        "//rplidar_lib/hal:util",
    ],
)
