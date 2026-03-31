# vibe_coding_practice

## Project Overview
This is a C++ project framework designed for AI Agent development with TDD (Test-Driven Development) practices.

## Project Requirements

### Project Structure
- `src/`: Source code directory
- `test/`: Test code directory
- `.github/`: GitHub project metadata and Copilot guidance
  - `copilot-instructions.md`: repository-level instructions for GitHub Copilot
  - `instructions/`: supplemental instruction documents
- `.trae/`: legacy Trae IDE content kept for backward compatibility
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

# experience 
- 使用 trea自动模式开发，感觉和Claude code的使用体验差距很大
- 流行的模型需要排队
## copilot 
- 不写注释
- 不按照要求使用TDD开发，直接写代码
- 无法解决glfw， glad等依赖，反复删除添加，需要人工解决
- 不写测试，从始至终使用一个测试文件
- 类结构不合理
- need rework, this must be fixed 

## Copilot Project Compatibility

This repository now includes GitHub Copilot project instructions under:

- `.github/copilot-instructions.md`

If you are using GitHub Copilot coding agent features, keep project-specific guidance in `.github/` to ensure the agent can load and follow it consistently.
