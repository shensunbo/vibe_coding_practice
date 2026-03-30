// Game.cpp - Main game class implementation for 2D fighting game

#include "Game.h"

Game::Game() : input(nullptr), currentState(GAME_STATE_MENU) {
}

Game::~Game() {
    shutdown();
}

bool Game::initialize() {
    // Initialize renderer
    if (!renderer.initialize(800, 600, "2D Fighting Game")) {
        return false;
    }

    // Create input system
    input = new Input(renderer.getWindow());

    return true;
}

void Game::run() {
    // Main game loop
    while (!renderer.shouldClose()) {
        // Handle input
        handleInput();

        // Update game state
        update();

        // Render
        render();

        // Swap buffers
        renderer.swapBuffers();
    }
}

void Game::shutdown() {
    if (input) {
        delete input;
        input = nullptr;
    }
    renderer.shutdown();
}

void Game::handleInput() {
    // Process input
    renderer.processInput();
    input->update();

    // Handle common input
    if (input->isKeyPressed(GLFW_KEY_ESCAPE)) {
        changeState(GAME_STATE_EXIT);
    }

    // Handle state-specific input
    switch (currentState) {
        case GAME_STATE_MENU:
            // TODO: Menu input handling
            break;
        case GAME_STATE_BATTLE:
            // TODO: Battle input handling
            break;
        case GAME_STATE_EXIT:
            break;
    }
}

void Game::update() {
    // Update state-specific logic
    switch (currentState) {
        case GAME_STATE_MENU:
            // TODO: Menu update logic
            break;
        case GAME_STATE_BATTLE:
            // TODO: Battle update logic
            break;
        case GAME_STATE_EXIT:
            // Exit the game
            renderer.shutdown();
            break;
    }
}

void Game::render() {
    // Clear screen
    renderer.clear();

    // Render state-specific content
    switch (currentState) {
        case GAME_STATE_MENU:
            // TODO: Menu rendering
            break;
        case GAME_STATE_BATTLE:
            // TODO: Battle rendering
            break;
        case GAME_STATE_EXIT:
            break;
    }
}

void Game::changeState(GameState newState) {
    currentState = newState;

    // TODO: State-specific initialization
}
