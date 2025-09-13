#ifndef B17E3C16_59B7_48CA_A3DF_DBEB9463A2F3
#define B17E3C16_59B7_48CA_A3DF_DBEB9463A2F3

#include <raylib-cpp.hpp>
#include "GameObject.h"
#include "Player.h"
#include "Tile.h"

/**
 * @class CollisionHandler
 * @brief Handles collision detection between game objects.
 * 
 * The CollisionHandler class provides functionality to check for collisions
 * between instances of GameObject using axis-aligned bounding box (AABB) collision detection.
 */
class CollisionHandler 
{
    public:
        CollisionHandler() = default;
        /**
         * @brief Checks for collision between two GameObject instances.
         * @param obj1 The first game object.
         * @param obj2 The second game object.
         * @return true if the objects collide, false otherwise.
         */
        bool checkCollision(const GameObject& obj1, const GameObject& obj2) const;
        /** @brief 
         * 
         * @param player 
         * @param tile 
         */
        void PlayerTileCollision(Player& player, Tile& tile);
        /** @brief 
         * 
         */
        virtual ~CollisionHandler() = default;
};

#endif /* B17E3C16_59B7_48CA_A3DF_DBEB9463A2F3 */
