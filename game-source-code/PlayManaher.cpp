// PlayManager.cpp
#include "PlayManager.h"

game_States PlayManager::update(game_States current_state) 
{
    // Transitions that used to live in Menu.cpp
    if (IsKeyPressed(KEY_P))          return game_States::Paused;
    if (IsKeyPressed(KEY_BACKSPACE))  return game_States::Game_Over;

    // Stay in Playing
    return current_state;
}

void PlayManager::draw(Earth& earth, Player& player) 
{
    // Drawing that used to live in Menu.cpp
    ClearBackground(BLACK);
    earth.Draw();
    player.controlled_Move();
    player.draw();
}
