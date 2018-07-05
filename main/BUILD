# Main method for this program.

cc_binary(
    name = "collect_sweeps_main",
    srcs = ["collect_sweeps_main.cc"],
    deps = [
        "//main/proto:lidar_scan_cc_proto",
        "//rplidar_lib:rplidar",
        "//rplidar_lib:rplidar_driver",
        "//util:commandlineflags",
        "@com_github_gflags_gflags//:gflags",
        "@com_google_absl//absl/strings",
        "@com_google_absl//absl/time",
    ],
)

cc_binary(
    name = "turn_servo_main",
    srcs = ["turn_servo_main.cc"],
    deps = [
        "//dynamixel_sdk_linux:dynamixel_sdk",
        "@com_google_absl//absl/strings",
        "@com_google_absl//absl/time",
    ],
)
