# AI Agent Instructions

## Coding Standards

### Comments
- All comments must be in English
- Use a common documentation-friendly comment style (e.g., Doxygen)
- Comment all functions, classes, and important code sections
- Ensure comments are clear and explain the purpose and functionality of the code

### Testing
- Follow Test-Driven Development (TDD) practices
- Write tests before implementing functionality
- After completing each task, compile and run tests to ensure code quality
- Use Google Test (GTest) for unit testing

## Project Structure

- `src/`: Source code directory
- `test/`: Test code directory
- `.trae/`: Trea IDE recognized directory for AI agent related content
  - `instructions/`: AI agent instructions
  - `skills/`: AI agent skills
  - `spec/`: AI agent specifications
  - `memory/`: AI agent memory
  - `logs/`: AI agent logs
- `scripts/`: Build and test scripts

## Build System

- Use Bazel as the build tool
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
