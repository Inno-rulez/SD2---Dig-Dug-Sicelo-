#ifndef DE374A09_A49B_48C4_BC30_F17C51B12019
#define DE374A09_A49B_48C4_BC30_F17C51B12019

#include <raylib-cpp.hpp>
#include <algorithm>
#include "Movable.h"

/**
 * @class Player
 * @brief Represents the player character in the game.
 * 
 * The Player class extends the Movable class, adding specific functionality
 * for player movement and rendering.
 */
class Player : public Movable
{   
    public:
        /**
         * @brief Constructs a Player object with position, size, active state, and direction.
         * @param pos The position of the player.
         * @param size_ The size of the player (default: {20, 20}).
         * @param active Whether the player is active (default: true).
         * @param dir The initial direction vector (default: {0, 0}).
         */
        Player(Vector2 pos = Vector2{490, 300}, Vector2 size_ = Vector2{40, 40}, bool active = true, Vector2 dir = Vector2{0,0})
        : Movable(pos, size_, active, dir) {setSpeed(2.0f);}

        /**
         * @brief Renders the player on the screen.
         * 
         * This function draws the player as a green rectangle at its current position.
         */
        void draw() const override 
        {
            DrawRectangle(static_cast<int>(GetPosition().x), static_cast<int>(GetPosition().y),
                        static_cast<int>(GetSize().x), static_cast<int>(GetSize().y), BLUE);
        }
        /**
         * @brief Destroy the Player object
         * 
         * @brief Handles player movement based on user input.
         * 
         * This function updates the player's position according to keyboard input.
         */
        void controlled_Move(int window_Width = 1000, int window_Height = 1000);

        virtual ~Player() = default;
};

#endif /* DE374A09_A49B_48C4_BC30_F17C51B12019 */
