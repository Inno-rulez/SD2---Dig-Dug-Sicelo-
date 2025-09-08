#ifndef E79680E5_9B67_4F3C_AFFE_7906DF5974B4
#define E79680E5_9B67_4F3C_AFFE_7906DF5974B4

#include <raylib-cpp.hpp>
#include <string>
#include "GameStates.h"

/**
 * @brief 
 * 
 * @brief Manages non-playing states in the game.
 *
 * This class handles updates and drawing for game states
 * where the player is not actively playing (e.g., menus, pause screens).
 */
class NonPlayingManager 
{
public:
    NonPlayingManager() = default;
    /**
     * @brief Updates the current non-playing game state.
     * 
     * This function processes input and logic for non-playing states
     * such as menus or pause screens, and returns the potentially updated state.
     * 
     * @param current_state The current non-playing game state.
     * @return The updated game state after processing.
     */
    game_States update(game_States current_state);
    /// @brief 
    /// @param current_state 
    void draw(game_States current_state);
};

#endif /* E79680E5_9B67_4F3C_AFFE_7906DF5974B4 */
