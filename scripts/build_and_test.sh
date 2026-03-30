#!/bin/bash

# Build and test script for 2D fighting game

echo "Building the project..."
bazel build //src:main

if [ $? -eq 0 ]; then
    echo "Build successful!"
    echo "Running tests..."
    bazel test //test:agent_test
    
    if [ $? -eq 0 ]; then
        echo "All tests passed!"
    else
        echo "Some tests failed."
    fi
else
    echo "Build failed."
fi
