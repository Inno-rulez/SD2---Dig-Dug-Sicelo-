#ifndef AA659600_5AB7_43BD_9360_FE6B0988E82B
#define AA659600_5AB7_43BD_9360_FE6B0988E82B

#include <raylib-cpp.hpp>
#include <vector>
#include <cmath>
#include "Movable.h"
#include "Player.h"
#include "Earth.h"

using namespace std;

/**
 * @class Monster
 * @brief Represents a monster character in the game.
 * 
 * The Monster class extends the Movable class, adding specific functionality
 * for monster movement and rendering.
 */

enum class MonsterSate { Physical, Disembodied};

class Monster : public Movable
{   
    private:
        MonsterSate state;
    public:
        /**
         * @brief Constructs a Monster object with position, size, active state, and direction.
         * @param pos The position of the monster.
         * @param size_ The size of the monster (default: {20, 20}).
         * @param active Whether the monster is active (default: true).
         * @param dir The initial direction vector (default: {0, 0}).
         */
        Monster(Vector2 pos = Vector2{200, 200}, Vector2 size_ = Vector2{40, 40}, bool active = true, Vector2 dir = Vector2{0,0})
        : Movable(pos, size_, active, dir), state(MonsterSate::Physical) {setSpeed(1.0f);}
        /**
         * @brief Renders the monster on the screen.
         * 
         * This function draws the monster as a red rectangle at its current position.
         */
        void draw() const override;

        /**
         * @brief Gets possible moves for the monster when in physical state.
         * 
         * This function checks potential moves (up, down, left, right) and returns
         * a list of valid positions that do not collide with the Earth.
         * 
         * @param earth The Earth object to check for collisions.
         * @return A vector of valid move positions as raylib::Vector2.
         */
        vector<Vector2> getPhysicalMoves(Earth& earth) const;

        /**
         * @brief Sets the monster's direction towards the player while avoiding collisions.
         * 
         * This function calculates the direction vector from the monster to the player,
         * normalizes it, and sets it as the monster's direction if it does not lead to a collision.
         * 
         * @param player The Player object to chase.
         * @param earth The Earth object to check for collisions.
         */
        void setPhysicalDirection(const Player& player, Earth& earth);

        /**
         * @brief Handles movement when the monster is in disembodied state.
         * 
         * This function allows the monster to move freely without collision checks.
         */
        void disembodiedMove();

        float getPlayerDistance(const Player& player) const;

        /**
         * @brief Chases the player by setting the monster's direction towards the player's position.
         * 
         * This function calculates the direction vector from the monster to the player,
         * normalizes it, and sets it as the monster's direction.
         * 
         * @param player The Player object to chase.
         */
        void chasePlayer(const Player& player); 

        virtual ~Monster() = default;
}; 

#endif /* AA659600_5AB7_43BD_9360_FE6B0988E82B */
