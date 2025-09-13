#include "NoPlayManager.h"

game_States NonPlayingManager::update(game_States current_state) 
{
    switch (current_state) 
    {
        case game_States::Splash_Screen:
            if (IsKeyPressed(KEY_ENTER))     return game_States::Playing;
            if (IsKeyPressed(KEY_I))         return game_States::Instructions;
            if (IsKeyPressed(KEY_BACKSPACE)) return game_States::Game_Over;
            break;

        case game_States::Instructions:
            if (IsKeyPressed(KEY_BACKSPACE)) return game_States::Splash_Screen;
            break;

        case game_States::Paused:
            if (IsKeyPressed(KEY_ENTER))     return game_States::Playing;
            if (IsKeyPressed(KEY_BACKSPACE)) return game_States::Splash_Screen;
            break;

        case game_States::Game_Over:
            if (IsKeyPressed(KEY_ENTER))     return game_States::Splash_Screen;
            break;

        default:
            break;
    }
    return current_state; // unchanged if no input
}

void NonPlayingManager::draw(game_States current_state) 
{
    switch (current_state) 
    {
        case game_States::Splash_Screen:
            ClearBackground(BLACK);
            DrawText("Splash Screen", 140, 200, 50, LIGHTGRAY);
            DrawText("Press ENTER to start playing", 140, 280, 30, RAYWHITE);
            DrawText("Press I to view instructions", 140, 320, 30, RAYWHITE);
            DrawText("Press BACKSPACE to go to Game Over screen", 140, 360, 30, RAYWHITE);
            break;

        case game_States::Instructions:
            ClearBackground(DARKGRAY);
            DrawText("Instructions", 160, 200, 50, RAYWHITE);
            DrawText("Move with arrows. Dig by moving through dirt.", 160, 280, 30, RAYWHITE);
            DrawText("Press BACKSPACE to go back to Splash Screen", 160, 320, 30, RAYWHITE);
            break;

        case game_States::Paused:
            DrawText("Paused", 160, 200, 50, YELLOW);
            DrawText("Press ENTER to resume", 160, 280, 30, RAYWHITE);
            DrawText("Press BACKSPACE to return to Splash Screen", 160, 320, 30, RAYWHITE);
            break;

        case game_States::Game_Over:
            DrawText("Game Over", 160, 200, 50, RAYWHITE);
            DrawText("Press ENTER to return to Splash Screen", 160, 280, 30, RAYWHITE);
            break;

        default:
            break;
    }
}
