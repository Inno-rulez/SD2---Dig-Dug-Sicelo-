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

void Menu::display(Earth& earth, Player& player, Monster& monster) 
{
    while (!game_Window.ShouldClose()) 
    {
        BeginDrawing();

        if (current_State == game_States::Playing) 
        {
            current_State = playManager->update(current_State);
            playManager->draw(earth, player, monster);
        } 
        else 
        {
            current_State = nonPlaying->update(current_State);
            nonPlaying->draw(current_State);
        }
        EndDrawing();
    }
}

Menu::~Menu() 
{
    // Destructor
}
