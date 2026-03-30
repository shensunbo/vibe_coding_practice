# vibe_coding_practice

## Project Overview
This is a C++ project framework designed for AI Agent development with TDD (Test-Driven Development) practices.

## Project Requirements

### Project Structure
- `src/`: Source code directory
- `test/`: Test code directory
- `.trae/`: Trea IDE recognized directory for AI agent related content
  - `instructions/`: AI agent instructions
  - `skills/`: AI agent skills
  - `spec/`: AI agent specifications
  - `memory/`: AI agent memory
  - `logs/`: AI agent logs
- `scripts/`: Build and test scripts

### Build System
- Uses Bazel as the build tool
- Google Test (GTest) for unit testing

## How to Build and Test
```bash
# Build the project
bazel build //src:main

# Run tests
bazel test //test:agent_test

# Use the build and test script
./scripts/build_and_test.sh
```

