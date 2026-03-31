// main.cc - Main entry point for 2D fighting game

#include "game/Game.h"

int main() {
    game::Game game;

    if (!game.initialize()) {
        return -1;
    }

    game.run();

    return 0;
}
