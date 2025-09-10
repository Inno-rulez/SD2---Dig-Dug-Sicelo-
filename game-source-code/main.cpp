#include <raylib-cpp.hpp>
#include "Menu.h"
#include "Tile.h"

int main() {
    auto game_Menu = Menu{};
    auto earth = Earth{1000, 1000, 8};
    game_Menu.display(earth);
    return 0;
}