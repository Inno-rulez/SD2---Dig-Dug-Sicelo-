#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <raylib-cpp.hpp>
#include <unordered_map>
#include <iostream>
#include "Player.h"
#include "Earth.h"

using namespace std;

// Player Tests
TEST_CASE("Player is created with correct attributes") {
    Player player(Vector2{100, 150}, Vector2{50, 50}, true, Vector2{0,0});
    CHECK(player.GetPosition().x == 100);
    CHECK(player.GetPosition().y == 150);
    CHECK(player.GetSize().x == 50);
    CHECK(player.GetSize().y == 50);
}

TEST_CASE("Player movement updates position correctly") {
    Player player(Vector2{100, 150}, Vector2{50, 50}, true, Vector2{0,0});
    player.setSpeed(5.0f);

    // Move Up
    player.up();
    player.Move();
    CHECK(player.GetPosition().y == 145); // Moved up by speed

    // Move Down
    player.down();
    player.Move();
    CHECK(player.GetPosition().y == 150); // Back to original position

    // Move Left
    player.left();
    player.Move();
    CHECK(player.GetPosition().x == 95); // Moved left by speed

    // Move Right
    player.right();
    player.Move();
    CHECK(player.GetPosition().x == 100); // Back to original position

    // Stop
    player.stop();
    player.Move();
    CHECK(player.GetPosition().x == 100); // No movement
    CHECK(player.GetPosition().y == 150); // No movement
}