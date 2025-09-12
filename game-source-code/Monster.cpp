#include "Monster.h"

void Monster::draw() const 
{
    if (state == MonsterSate::Disembodied) 
    {
        // Draw a semi-transparent monster when disembodied
        DrawRectangle(static_cast<int>(GetPosition().x), static_cast<int>(GetPosition().y),
                static_cast<int>(GetSize().x), static_cast<int>(GetSize().y), RAYWHITE);
        return;
    }
    else if (state == MonsterSate::Physical) 
    {
        // Draw a solid monster when physical
        DrawRectangle(static_cast<int>(GetPosition().x), static_cast<int>(GetPosition().y),
                static_cast<int>(GetSize().x), static_cast<int>(GetSize().y), RED);
    }
}