#include "Player.h"

void Player::controlled_Move(int window_Width, int window_Height) 
{
    if (IsKeyDown(KEY_UP)) 
    {
        up();
    }
    else if (IsKeyDown(KEY_DOWN)) 
    {
        down();
    }
    else if (IsKeyDown(KEY_LEFT)) 
    {
        left();
    }
    else if (IsKeyDown(KEY_RIGHT)) 
    {
        right();
    }
    else 
    {
        stop();
        return; // No movement if no key is pressed
    }
    Move();

    // Ensure the player stays within window bounds
    position.x = std::max(0.0f, std::min(position.x, static_cast<float>(window_Width - GetSize().x)));
    position.y = std::max(0.0f, std::min(position.y, static_cast<float>(window_Height - GetSize().y)));
}
