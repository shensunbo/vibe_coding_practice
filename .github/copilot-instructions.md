# GitHub Copilot Instructions

## Project context
- This repository is a C++ 2D fighting game prototype using OpenGL.
- Build system: Bazel.
- Testing framework: GoogleTest.
- Source code is under `src/`; tests are under `test/`.

## Coding standards
- Keep code and identifiers clear and consistent with existing C++ style.
- Write all comments in English.
- Use documentation-friendly comments for non-trivial classes/functions when needed.
- Prefer small, testable units and avoid introducing unrelated refactors.

## Development workflow
- Follow TDD where practical: add or update tests with behavior changes.
- Validate changes by running project build/tests before completion.
- Use existing scripts and Bazel targets:
  - Build: `bazel build //src:main`
  - Test: `bazel test //test:agent_test`
  - Combined script: `./scripts/build_and_test.sh`

## Scope guardrails
- Do not add external runtime assets; graphics/audio are intended to be program-generated.
- Keep changes focused on the requested task and preserve current gameplay architecture.
