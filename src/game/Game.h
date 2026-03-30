// Game.h - Main game class for 2D fighting game

#ifndef GAME_H
#define GAME_H

#include "Renderer.h"
#include "Input.h"

enum GameState {
    GAME_STATE_MENU,
    GAME_STATE_BATTLE,
    GAME_STATE_EXIT
};

class Game {
public:
    Game();
    ~Game();

    bool initialize();
    void run();
    void shutdown();

private:
    Renderer renderer;
    Input* input;
    GameState currentState;

    void handleInput();
    void update();
    void render();
    void changeState(GameState newState);
};

#endif // GAME_H
