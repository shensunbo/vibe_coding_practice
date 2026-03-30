#!/bin/bash

# 构建和测试脚本

echo "=== Building and Testing C++ Project ==="

# 构建项目
echo "Building project..."
bazel build //src:main
if [ $? -ne 0 ]; then
    echo "Build failed!"
    exit 1
fi

echo "Build successful!"

# 运行测试
echo "Running tests..."
bazel test //test:agent_test
if [ $? -ne 0 ]; then
    echo "Tests failed!"
    exit 1
fi

echo "Tests passed!"

echo "=== Build and Test Completed Successfully ==="
