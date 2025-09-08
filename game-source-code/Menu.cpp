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

        if (current_State == game_States::Playing) {
            ClearBackground(BROWN);
            DrawText("Playing", 300, 200, 40, RAYWHITE);
            DrawText("Press P to pause", 300, 280, 24, RAYWHITE);
            DrawText("Press BACKSPACE to go to Game Over screen", 300, 320, 24, RAYWHITE);

            if (IsKeyPressed(KEY_P))      current_State = game_States::Paused;
            if (IsKeyPressed(KEY_BACKSPACE)) current_State = game_States::Game_Over;
        } else {
            // Delegate to the non playing manager
            current_State = nonPlaying->update_and_draw(current_State);
        }
        EndDrawing();
    }
}

Menu::~Menu() 
{
    // Destructor
}
