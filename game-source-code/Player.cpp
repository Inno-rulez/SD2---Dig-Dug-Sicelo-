#include "Player.h"

void Player::controlled_Move() 
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
}
