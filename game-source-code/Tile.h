#ifndef F0B6DE39_573C_47BA_A1A5_D9441E0204C3
#define F0B6DE39_573C_47BA_A1A5_D9441E0204C3

#include <raylib-cpp.hpp>
#include "GameObject.h"

using namespace std;

/**
 * @brief Represents a tile in the game world.
 * 
 * The Tile class inherits from GameObject and adds color information.
 * It can be used to represent static or interactive tiles in the game.
 */
class Tile : public GameObject
{
    public:
        /**
         * @brief Constructs a Tile object with position, size, active state, and color.
         * @param pos The position of the tile.
         * @param size_ The size of the tile.
         * @param active Whether the tile is active (default: true).
         * @param color_ The color of the tile (default: WHITE).
         */
        Tile(Vector2 pos, Vector2 size_ = Vector2{5,5}, bool active = true, raylib::Color color_ = WHITE)
        : GameObject(pos, size_, active), color(color_) {}
        /**
         * @brief 
         * 
         * @brief Draws the tile on the screen.
         *
         * This function renders the tile using its position, size, and color.
         */
        void Draw() const;
        virtual ~Tile() = default;

    private:
        raylib::Color color;
};

#endif /* F0B6DE39_573C_47BA_A1A5_D9441E0204C3 */
