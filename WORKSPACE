# Bazel workspace file for 2D fighting game

# Load external dependencies
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

# GLFW
http_archive(
    name = "glfw",
    strip_prefix = "glfw-3.3.8",
    urls = ["https://github.com/glfw/glfw/archive/refs/tags/3.3.8.tar.gz"],
    build_file_content = """
package(default_visibility = ["//visibility:public"])

cc_library(
    name = "glfw",
    hdrs = glob(["include/GLFW/*.h"]),
    includes = ["include"],
    linkopts = ["-lglfw"],
)
""",
)

# Google Test
http_archive(
    name = "gtest",
    strip_prefix = "googletest-release-1.12.1",
    urls = ["https://github.com/google/googletest/archive/refs/tags/release-1.12.1.tar.gz"],
)
