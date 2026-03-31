# C++ 2D Fighting Game Project Setup and Development Log

## Date: 2026-03-31

---

## 1. Project Cleanup & Preparation

- **Fix all build errors**, including failing unit tests.
- Ensure the repository is clean and buildable from scratch.
- Make the repo suitable for starting a new game project using modern C++ practices.

---

## 2. Skills & Abilities

- Add all necessary utilities, testing tools, and game development abilities for:
  - Modern C++ game development.
  - Real-time 2D rendering with OpenGL.
  - Test-driven development (TDD) workflows.
  - Efficient logging using spdlog.
  - Bazel as the build system.

---

## 3. Development Methodology

- Use Test Driven Development (TDD) throughout.
  - For each new feature or bugfix, write tests first.
  - Ensure all critical gameplay logic is covered by unit tests.
- Keep the repo free of failing tests at all times.

---

## 4. Game Prototype Requirements

### Basic Gameplay

- Create a simple 2D fighting game prototype inspired by “King of Fighters” (KOF).
- Use OpenGL for graphics rendering.
- Do **not** use external images/audio; generate all assets procedurally at runtime.

### Core Features:

1. **Characters**
    - Two fighters: one user-controlled, one AI-controlled.
    - Simple attacks (2 or 3 kinds) with differing damages and ranges.
    - Movements: jump, walk, basic dodge.
    - Distinct health, with health bars shown.
2. **Game Mechanics**
    - Health, damage, attack range.
    - Win/loss conditions (KO or time over).
3. **AI**
    - Basic behavior: approach, retreat, attack, defend/block.
    - Simple decision-making (rule-based, no machine learning or complex FSM for initial version).
4. **Rendering**
    - Procedurally generated simple character shapes (rectangles, circles, polygons, stick figures).
    - Arena with background generated via code.
    - Use OpenGL primitives for drawing.
5. **Performance & Stability**
    - Game must run smoothly: no crashes, hangs, or critical bugs.
    - Error handling where appropriate.
6. **Testing/Quality**
    - Unit tests for key game logic (combat resolution, health/damage, win/loss).
    - Use a C++ test framework (e.g., Google Test, Catch2).
    - Tests runnable via Bazel.

### Build System

- Use Bazel for all build, run, and test tasks.
- All third-party dependencies managed via Bazel WORKSPACE.

### Logging

- Use spdlog for logging (performance-friendly, readable, configurable severity).

---

## 5. Documentation

- Comment code to explain mechanisms and design choices.
- Write a clear README explaining:
    - Build/Run/Test instructions.
    - Dependency list (with rationale for each).
    - Project structure.
    - How to extend the game (for future work).

---

## 6. Development Log

- Maintain a log of:
    - Key design decisions and rationale.
    - Challenges encountered and solutions/workarounds.
    - Notable implementation details or trade-offs.

---

## 7. Additional Guidelines

- You may add dependencies as necessary, but:
    - Document each in the README.
    - Justify their use.
- If instructions or requirements change during development, keep this document and the README up to date.
- Reference or draw inspiration from “King of Fighters” (visual/gameplay style), but do not use unlicensed assets.

---

## 8. Limitations

- No external art or sound resources: all assets generated at runtime.
- Initial version: focus on core mechanics without advanced animation or effects.
- Only two characters.
- Aim for maximum clarity in logic and structure (prioritize maintainability).

---

## 9. To-Do Summary

- [ ] Fix all build/unit test errors; ensure green builds with Bazel.
- [ ] Set up Bazel build/test for the whole project.
- [ ] Integrate spdlog and C++ test framework.
- [ ] Implement game core systems according to TDD.
- [ ] Document all steps and design decisions.

---
