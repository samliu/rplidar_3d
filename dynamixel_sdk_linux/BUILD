# BUILD rules for USB2AX (Dynamixel) SDK.
package(default_visibility = ["//visibility:public"])

cc_library(
    name = "dynamixel_sdk",
    srcs = ["dynamixel.c"],
    hdrs = ["dynamixel.h"],
    copts = ["-std=c99"],
    deps = [
        ":dxl_hardware_abstraction_layer",
    ],
)

cc_library(
    name = "dxl_hardware_abstraction_layer",
    srcs = ["dxl_hal.c"],
    hdrs = ["dxl_hal.h"],
)

cc_library(
    name = "ax12_control_table",
    hdrs = ["ax12_control_table.h"],
)
