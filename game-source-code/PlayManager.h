#ifndef DFFB9813_6086_4CC3_AEC9_34F70C484613
#define DFFB9813_6086_4CC3_AEC9_34F70C484613

#include <raylib-cpp.hpp>
#include "GameStates.h"

/**
 * @class PlayManager
 * @brief Manages the logic and rendering for the Playing state of the game.
 */
class PlayManager 
{
    public:
        PlayManager() = default;

        // Process input/logic for the Playing state and return (possibly) a new state
        game_States update(game_States current_state);
        /**
         * @brief Renders the Playing screen.
         */
        void draw();
};

#endif /* DFFB9813_6086_4CC3_AEC9_34F70C484613 */
