#include "Movable.h"

void Movable::up() 
{
    direction = Vector2{0, -1};
}

void Movable::down() 
{
    direction = Vector2{0, 1};
}

void Movable::left() 
{
    direction = Vector2{-1, 0};
}  

void Movable::right() 
{
    direction = Vector2{1, 0};
}

void Movable::Move() 
{
    position.x += direction.x * speed;
    position.y += direction.y * speed;
}