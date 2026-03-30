# Bazel WORKSPACE file for C++ project with Google Test

# Load the rules for C++
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

# rules_cc dependency
http_archive(
    name = "rules_cc",
    urls = ["https://github.com/bazelbuild/rules_cc/releases/download/0.0.8/rules_cc-0.0.8.tar.gz"],
    sha256 = "f245f6c71395517726207b677b657b8283164d774c8a723f4a1b3840c602b53d",
)

# Google Test dependency
http_archive(
    name = "com_google_googletest",
    urls = ["https://github.com/google/googletest/archive/refs/tags/release-1.12.1.tar.gz"],
    strip_prefix = "googletest-release-1.12.1",
    sha256 = "81964fe578e9bd7c94dfdb09c8e4d6e6759e19967e397dbea48d1c10e45d0df2",
)

# Load Google Test rules
load("@com_google_googletest//:googletest.bzl", "gtest_repository")

# Initialize Google Test
gtest_repository(name = "gtest")
