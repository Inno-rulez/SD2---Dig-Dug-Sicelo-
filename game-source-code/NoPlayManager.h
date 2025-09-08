#ifndef E79680E5_9B67_4F3C_AFFE_7906DF5974B4
#define E79680E5_9B67_4F3C_AFFE_7906DF5974B4

#include <raylib-cpp.hpp>
#include <string>
#include "GameStates.h"

class NonPlayingManager {
public:
    NonPlayingManager() = default;
    // Draws the current non playing screen and handles its input
    // Returns the next requested state
    game_States update_and_draw(game_States current_state);
};

#endif /* E79680E5_9B67_4F3C_AFFE_7906DF5974B4 */
