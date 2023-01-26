package(default_visibility = ["//visibility:public"])

cc_library(
    name = "frame_rate_counter",
    srcs = ["frame_rate_counter.cc"],
    hdrs = ["frame_rate_counter.h"],
    visibility = ["//visibility:public"],
    deps = [
        "//mediapipe/framework:calculator_framework",
        "//mediapipe/framework:calculator_options_cc_proto",
        "//mediapipe/framework/port:ret_check",
        "@com_google_absl//absl/memory",
        "@com_google_absl//absl/strings",
    ],
    alwayslink = 1,
)
