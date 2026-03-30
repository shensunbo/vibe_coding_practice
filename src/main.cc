// main.cc - Main entry point for 2D fighting game

#include "game/Game.h"

int main() {
    Game game;
    
    // Initialize game
    if (!game.initialize()) {
        return -1;
    }

    // Run game
    game.run();

    // Shutdown will be called automatically by the destructor

    return 0;
}
