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

## Skills

### Available Skills

The following skills are available for this project:

#### Global Skills (~/.agents/skills)

1. **game-development** - Comprehensive game development skills
2. **game-development/2d-games** - 2D game development specific skills
3. **cpp-testing** - C++ testing best practices and techniques
4. **cpp-coding-standards** - C++ coding standards and best practices

### Auto-Loading Skills

The following skills are automatically loaded every time a new context is started:

1. **cpp_programming_advanced**
2. **game_development_2d_fighting**
3. **game-development/2d-games**
4. **cpp-testing**

These skills will be used to assist with game development tasks, including C++ programming, game design, implementation, and testing.

### Using Skills

To explicitly use a skill, you can reference it in your requests. For example:

- "Use the cpp_programming_advanced skill to optimize this code"
- "Use the game_development_2d_fighting skill to implement a combo system"
- "Use the cpp-testing skill to write unit tests for this feature"

The agent will automatically apply the relevant skills based on the context of your request.
