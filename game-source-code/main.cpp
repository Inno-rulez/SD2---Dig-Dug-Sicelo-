#include <raylib-cpp.hpp>
#include "Menu.h"
#include "Tile.h"

int main() {
    auto game_Menu = Menu{};
    auto earth = Earth{900, 900, 5};
    auto player = Player{};
    game_Menu.display(earth, player);
    return 0;
}