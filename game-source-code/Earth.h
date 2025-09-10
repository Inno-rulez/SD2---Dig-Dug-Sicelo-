#ifndef A63A4E84_DEDB_498F_9E2F_2BC4D4A4420D
#define A63A4E84_DEDB_498F_9E2F_2BC4D4A4420D

#include <raylib-cpp.hpp>
#include <vector>
#include "Tile.h"

using namespace std;

class Earth
{
private:
    vector<vector<Tile>> tiles;
public:
    Earth(int window_Height, int window_Width, int tile_Size = 8);
    void add_Layer(int tile_Size = 8, int start_row = 0, int depth = 0, int cols = 0, raylib::Color color = YELLOW);
    void Draw() const;
    virtual ~Earth() = default;
};


#endif /* A63A4E84_DEDB_498F_9E2F_2BC4D4A4420D */
