// Menu.cpp
#include "Menu.h"
#include <raylib-cpp.hpp>

Menu::Menu(int width, int height, int fps, string t)
    : screen_Width(width),
    screen_Height(height),
    target_FPS(fps),
    title(t),
    game_Window(width, height, t) // raylib::Window constructor
{
    SetTargetFPS(target_FPS);
    current_State = game_States::Splash_Screen;
}

void Menu::display() {
    while (!game_Window.ShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        if (current_State == game_States::Splash_Screen) {
            DrawText("Splash Screen", 300, 200, 40, LIGHTGRAY);

            // Instructions
            DrawText("Press ENTER to start playing", 300, 280, 24, RAYWHITE);
            DrawText("Press I to view instructions", 300, 320, 24, RAYWHITE);
            DrawText("Press BACKSPACE to quit to Game Over screen", 300, 360, 24, RAYWHITE);

            if (IsKeyPressed(KEY_ENTER))   current_State = game_States::Playing;
            if (IsKeyPressed(KEY_I))       current_State = game_States::Instructions;
            if (IsKeyPressed(KEY_BACKSPACE))  current_State = game_States::Game_Over;
        }
        else if (current_State == game_States::Playing) {
            DrawText("Playing State", 300, 200, 40, GREEN);

            // Instructions
            DrawText("Press P to pause", 300, 280, 24, RAYWHITE);
            DrawText("Press BACKSPACE to quit to Game Over screen", 300, 320, 24, RAYWHITE);

            if (IsKeyPressed(KEY_P))       current_State = game_States::Paused;
            if (IsKeyPressed(KEY_BACKSPACE))  current_State = game_States::Game_Over;
        }
        else if (current_State == game_States::Paused) {
            DrawText("Paused State", 300, 200, 40, YELLOW);

            // Instructions
            DrawText("Press ENTER to resume", 300, 280, 24, RAYWHITE);
            DrawText("Press BACKSPACE to return to Splash Screen", 300, 320, 24, RAYWHITE);

            if (IsKeyPressed(KEY_ENTER))      current_State = game_States::Playing;
            if (IsKeyPressed(KEY_BACKSPACE))  current_State = game_States::Splash_Screen;
        }
        else if (current_State == game_States::Instructions) {
            DrawText("Instructions", 300, 200, 40, BLUE);

            // Basic game tips plus navigation
            DrawText("Move with arrows. Dig by moving through dirt.", 300, 280, 24, RAYWHITE);
            DrawText("Press BACKSPACE to go back to Splash Screen", 300, 320, 24, RAYWHITE);

            if (IsKeyPressed(KEY_BACKSPACE)) current_State = game_States::Splash_Screen;
        }
        else if (current_State == game_States::Game_Over) {
            DrawText("Game Over", 300, 200, 40, RED);

            // Instructions
            DrawText("Press ENTER to return to Splash Screen", 300, 280, 24, RAYWHITE);

            if (IsKeyPressed(KEY_ENTER)) current_State = game_States::Splash_Screen;
        }

        EndDrawing();
    }
}

Menu::~Menu() 
{
    // Destructor
}
