#include "Earth.h"

Earth::Earth(int window_Height, int window_Width, int tile_Size)
{
    auto rows = window_Height / tile_Size;
    auto cols = window_Width / tile_Size;

    auto start_row = 3 * rows / 25;
    add_Layer(tile_Size, start_row, rows/5, cols , YELLOW);
    start_row += rows/5;
    add_Layer(tile_Size, start_row, rows/5, cols , ORANGE);
    start_row += rows/5;
    add_Layer(tile_Size, start_row, rows/5, cols , RED);
    start_row += rows/5;
    add_Layer(tile_Size, start_row, 3 * rows / 25, cols , MAROON);
}

void Earth::add_Layer(int tile_Size, int start_Row, int depth, int cols, raylib::Color color)
{
    vector<Tile> temp_Tiles;
    Tile temp_Tile(Vector2{0,0});

    for (size_t j = start_Row; j < start_Row + depth; j++)
    {
        for (size_t i = 0; i < cols; i++)
        {
            temp_Tile = Tile(Vector2{static_cast<float>(i) * static_cast<float>(tile_Size),
                        static_cast<float>(j) * static_cast<float>(tile_Size)},
                        Vector2{static_cast<float>(tile_Size), static_cast<float>(tile_Size)},
                        true, color);

            temp_Tiles.push_back(temp_Tile);
        }
        tiles.push_back(temp_Tiles);
        temp_Tiles.clear();
    }
}

bool Earth::isObjectCollide(const GameObject& obj) const
{
    CollisionHandler collision_Handler;
    for (const auto& row : tiles)
    {
        for (const auto& tile : row)
        {
            if (collision_Handler.checkCollision(obj, tile))
            {
                return true;
            }
        }
    }
    return false;
}

void Earth::check_Player_Collisions(Player& player)
{
    CollisionHandler collision_Handler;
    for (auto& row : tiles)
    {
        for (auto& tile : row)
        {
            collision_Handler.PlayerTileCollision(player, tile);
        }
    }
}

void Earth::remove_Inactive_Tiles()
{
    for (auto& row : tiles)
    {
        row.erase(std::remove_if(row.begin(), row.end(),
                    [](const Tile& tile) { return !tile.getActive(); }),
                row.end());
    }
}

void Earth::Draw() const
{
    for (const auto& row : tiles)
    {
        for (const auto& tile : row)
        {
            tile.Draw();
        }
    }
}