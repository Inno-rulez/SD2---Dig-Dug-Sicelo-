#include <raylib-cpp.hpp>
#include "Menu.h"
#include "Tile.h"
#include "Earth.h"
#include "Player.h"
#include "Monster.h"

int main() {
    auto game_Menu = Menu{};
    auto earth = Earth{900, 900, 5};
    auto player = Player{};
    auto monster = Monster{Vector2{200, 85-20}, Vector2{40, 40}};
    game_Menu.display(earth, player, monster);
    return 0;
}