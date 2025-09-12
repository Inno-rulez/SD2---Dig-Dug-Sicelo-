#ifndef AA659600_5AB7_43BD_9360_FE6B0988E82B
#define AA659600_5AB7_43BD_9360_FE6B0988E82B

#include <raylib-cpp.hpp>
#include "Movable.h"

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

        virtual ~Monster() = default;
}; 

#endif /* AA659600_5AB7_43BD_9360_FE6B0988E82B */
