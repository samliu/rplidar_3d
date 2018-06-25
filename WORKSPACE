local_repository(
    # Name of the Abseil repository. This name is defined within Abseil's
    # WORKSPACE file, in its `workspace()` metadata
    name = "com_google_absl",

    # Expects Google's Abseil C++ library to be available in `/opt/cpp`.
    path = "/opt/cpp/abseil-cpp",
)

# proto_library, cc_proto_library, and java_proto_library rules implicitly
# depend on @com_google_protobuf for protoc and proto runtimes.
# This statement defines the @com_google_protobuf repo.
http_archive(
    name = "com_google_protobuf",
    sha256 = "cef7f1b5a7c5fba672bec2a319246e8feba471f04dcebfe362d55930ee7c1c30",
    strip_prefix = "protobuf-3.5.0",
    urls = ["https://github.com/google/protobuf/archive/v3.5.0.zip"],
)
