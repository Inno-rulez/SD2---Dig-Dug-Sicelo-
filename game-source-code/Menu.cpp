#include "Menu.h"

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
}

void Menu::display() {
    // Basic loop
    while (!game_Window.ShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("Window from Menu class!", 300, 300, 50, LIGHTGRAY);
        EndDrawing();
    }
}

Menu::~Menu() {
    // Destructor
}
