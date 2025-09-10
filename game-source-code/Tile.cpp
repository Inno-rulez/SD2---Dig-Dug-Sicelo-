#include "Tile.h"

void Tile::Draw() const
{
    auto rect = raylib::Rectangle{GetPosition().x, GetPosition().y, GetSize().x, GetSize().y};
    DrawRectanglePro(rect, {0,0}, 45.0f, color);
}