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

void Movable::stop() 
{
    direction = Vector2{0, 0};
}

void Movable::setDirection(Vector2 dir) 
{
    auto mag = std::sqrt(dir.x * dir.x + dir.y * dir.y);
    if (mag != 0) {
        direction = Vector2{dir.x / mag, dir.y / mag}; // Normalize the direction vector
    } else {
        direction = Vector2{0, 0}; // No movement if the direction is zero
    }
}

void Movable::Move() 
{
    position.x += direction.x * speed;
    position.y += direction.y * speed;
}