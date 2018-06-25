# Main method for this program.

# TODO(samcliu): Add utils library and clean up sweeps main.
# cc_library(
#     name = "",
#     srcs = [],
#     hdrs = [],
#     deps = [],
# )

cc_binary(
    name = "collect_sweeps_main",
    srcs = ["collect_sweeps_main.cc"],
    deps = [
        "//main/proto:lidar_scan_cc_proto",
        "//rplidar_lib:rplidar",
        "//rplidar_lib:rplidar_driver",
        "@com_google_absl//absl/strings",
        "@com_google_absl//absl/time",
    ],
)
