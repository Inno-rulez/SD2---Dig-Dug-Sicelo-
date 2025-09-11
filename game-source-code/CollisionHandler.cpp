#include "CollisionHandler.h"

bool CollisionHandler::checkCollision(const GameObject& obj1, const GameObject& obj2) const 
{
    auto rect1 = raylib::Rectangle(obj1.GetPosition().x, obj1.GetPosition().y, obj1.GetSize().x, obj1.GetSize().y);
    auto rect2 = raylib::Rectangle(obj2.GetPosition().x, obj2.GetPosition().y, obj2.GetSize().x, obj2.GetSize().y);
    return CheckCollisionRecs(rect1, rect2);
}

void CollisionHandler::PlayerTileCollision(Player& player, Tile& tile) 
{
    if (checkCollision(player, tile)) 
    {
        tile.deactivate();
    }
}