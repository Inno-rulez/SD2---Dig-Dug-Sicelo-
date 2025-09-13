#ifndef DFFB9813_6086_4CC3_AEC9_34F70C484613
#define DFFB9813_6086_4CC3_AEC9_34F70C484613

#include <raylib-cpp.hpp>
#include "GameStates.h"
#include "Earth.h"
#include "Player.h"
#include "Monster.h"

/**
 * @class PlayManager
 * @brief Manages the logic and rendering for the Playing state of the game.
 */
class PlayManager 
{
    public:
        PlayManager() = default;

        /**
         * @brief Processes input and logic for the Playing state.
         * @param current_state The current game state.
         * @return The updated game state after processing.
         */
        game_States update(game_States current_state);
        /** @brief 
         * 
         *
         * @brief Renders the Playing screen.
         */
        void draw(Earth& earth, Player& player, Monster& monster);
};

#endif /* DFFB9813_6086_4CC3_AEC9_34F70C484613 */
