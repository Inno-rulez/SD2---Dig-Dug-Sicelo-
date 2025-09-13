// PlayManager.cpp
#include "PlayManager.h"

game_States PlayManager::update(game_States current_state, Player& player) 
{
    // Transitions that used to live in Menu.cpp
    if (IsKeyPressed(KEY_BACKSPACE))        return game_States::Paused;
    if (isGameOver(player))                 return game_States::Game_Over;

    // Stay in Playing
    return current_state;
}

void PlayManager::updateObjects(Earth& earth, Player& player, Monster& monster) 
{
    earth.check_Player_Collisions(player);
    earth.remove_Inactive_Tiles();
    player.controlled_Move(900, 900);
    monster.chasePlayer(player, earth);
}

void PlayManager::draw(Earth& earth, Player& player, Monster& monster) 
{
    // Drawing that used to live in Menu.cpp
    ClearBackground(BLACK);
    earth.Draw();
    player.draw();
    monster.draw();
}
