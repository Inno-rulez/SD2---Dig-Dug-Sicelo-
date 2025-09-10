#include <raylib-cpp.hpp>
#include "Menu.h"
#include "Tile.h"

int main() {
    auto game_Menu = Menu{};
    auto tile = Tile({100, 100}); // Example usage of Tile class
    game_Menu.display(tile);
    return 0;
}