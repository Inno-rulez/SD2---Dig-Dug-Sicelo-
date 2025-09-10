#include "Tile.h"

void Tile::Draw() const
{
    DrawRectangleV(GetPosition(), GetSize(), color);
}