package(default_visibility = ["//visibility:public"])

# Be sure that all who include this also include `:timer` since we
# removed the circular dependency when we migrated to bazel.
cc_library(
    name = "arch_linux",
    hdrs = ["arch_linux.h"],
)

cc_library(
    name = "net_serial",
    srcs = ["net_serial.cc"],
    hdrs = ["net_serial.h"],
    deps = [
        ":arch_linux",
        "//rplidar_lib/hal:abs_rxtx",
    ],
)

cc_library(
    name = "thread",
    hdrs = ["thread.h"],
    deps = [
        ":arch_linux",
    ],
)

cc_library(
    name = "timer",
    srcs = ["timer.cc"],
    hdrs = [
        "arch_linux.h",
        "timer.h",
    ],
    deps = [
        "//rplidar_lib:rptypes",
    ],
)
