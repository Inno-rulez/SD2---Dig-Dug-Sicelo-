// PlayManager.cpp
#include "PlayManager.h"

game_States PlayManager::update(game_States current_state) {
    // Transitions that used to live in Menu.cpp
    if (IsKeyPressed(KEY_P))          return game_States::Paused;
    if (IsKeyPressed(KEY_BACKSPACE))  return game_States::Game_Over;

    // Stay in Playing
    return current_state;
}

void PlayManager::draw() {
    // Drawing that used to live in Menu.cpp
    ClearBackground(BLACK);
    DrawText("Playing", 300, 200, 40, RAYWHITE);
    DrawText("Press P to pause", 300, 280, 24, RAYWHITE);
    DrawText("Press BACKSPACE to go to Game Over screen", 300, 320, 24, RAYWHITE);
}
