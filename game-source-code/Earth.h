#ifndef A63A4E84_DEDB_498F_9E2F_2BC4D4A4420D
#define A63A4E84_DEDB_498F_9E2F_2BC4D4A4420D

#include <raylib-cpp.hpp>
#include <vector>
#include <algorithm>
#include "Tile.h"
#include "Player.h"
#include "CollisionHandler.h"

using namespace std;

/**
 * @class Earth
 * @brief Represents the Earth in the game, composed of tiles.
 *
 * The Earth class manages a grid of Tile objects, allowing layers to be added and drawn.
 */
class Earth
{
    private:
        /** @brief 
         * 
         */
        vector<vector<Tile>> tiles;

    public:
        /** @brief 
         * 
         * @param window_Height 
         * @param window_Width 
         * @param tile_Size 
         */
        Earth(int window_Height, int window_Width, int tile_Size = 4);

        /**
         * @brief Adds a layer of tiles to the Earth.
         * 
         * This function creates and adds a new layer of tiles to the Earth object.
         * 
         * @param tile_Size The size of each tile in the layer. Default is 8.
         * @param start_row The starting row for the layer. Default is 0.
         * @param depth The depth (number of rows) of the layer. Default is 0.
         * @param cols The number of columns in the layer. Default is 0.
         * @param color The color of the tiles in the layer. Default is YELLOW.
         */
        void add_Layer(int tile_Size = 4, int start_row = 0, int depth = 0, int cols = 0, raylib::Color color = YELLOW);

        bool isObjectCollide(const GameObject& obj) const;
        /** @brief 
         * 
         * @param player 
         */
        void check_Player_Collisions(Player& player);
        /** @brief 
         * 
         */
        void remove_Inactive_Tiles();

        /**
         * @brief Draws the Earth and its tiles on the screen.
         *
         * This function renders all the tiles that make up the Earth.
         */
        void Draw() const;
        virtual ~Earth() = default;
};


#endif /* A63A4E84_DEDB_498F_9E2F_2BC4D4A4420D */
