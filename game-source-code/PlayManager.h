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
        game_States update(game_States current_state, Player& player);
        /**
         * @brief Updates the game objects (Earth, Player, Monster) during the Playing state.
         * 
         * This function handles the logic updates for the Earth, Player, and Monster objects.
         * 
         * @param earth The Earth object to update.
         * @param player The Player object to update.
         * @param monster The Monster object to update.
         */
        void updateObjects(Earth& earth, Player& player, Monster& monster);
        /**
         * @brief Checks if the game is over based on the player's state.
         * 
         * This function determines if the game should transition to the Game Over state
         * by checking if the player is still active.
         * 
         * @param player The Player object to check.
         * @return true if the game is over (player is inactive), false otherwise.
         */
        bool isGameOver(const Player& player) const { return !player.getActive(); }
        /** @brief 
         * 
         *
         * @brief Renders the Playing screen.
         */
        void draw(Earth& earth, Player& player, Monster& monster);
};

#endif /* DFFB9813_6086_4CC3_AEC9_34F70C484613 */
