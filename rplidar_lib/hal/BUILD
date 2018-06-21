package(default_visibility = ["//visibility:public"])

cc_library(
    name = "abs_rxtx",
    hdrs = ["abs_rxtx.h"],
    deps = [
        "//rplidar_lib:rptypes",
    ],
)

cc_library(
    name = "event",
    hdrs = ["event.h"],
)

cc_library(
    name = "locker",
    hdrs = ["locker.h"],
)

cc_library(
    name = "thread",
    srcs = ["thread.cc"],
    hdrs = ["thread.h"],
    deps = [
        "//rplidar_lib:rplidar_cmd",
        "//rplidar_lib:rptypes",
        "//rplidar_lib:sdkcommon",
        "//rplidar_lib:rplidar",
        "//rplidar_lib/arch/linux:thread",
        # "//rplidar_lib/arch/macOS:thread",
        # "//rplidar_lib/arch/win32:winthread",
    ],
)

cc_library(
    name = "util",
    hdrs = ["util.h"],
)
