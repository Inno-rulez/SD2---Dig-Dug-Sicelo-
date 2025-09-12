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

TEST_CASE("Player movement is bound within window limits") {
    Player player(Vector2{40, 40}, Vector2{10, 10}, true, Vector2{0,0});
    player.setSpeed(15.0f);
    int window_Width = 200;
    int window_Height = 200;

    // Move Left beyond boundary
    player.left();
    for (int i = 0; i < 20; ++i) player.bound_Move(window_Width, window_Height); // Move multiple times
    CHECK_FALSE(player.GetPosition().x < 0); // Should not go below 0

    // Move Up beyond boundary
    player.up();
    for (int i = 0; i < 20; ++i) player.bound_Move(window_Width, window_Height); // Move multiple times
    CHECK_FALSE(player.GetPosition().y < 0); // Should not go below 0

    // Move Right beyond boundary
    player.right();
    for (int i = 0; i < 20; ++i) player.bound_Move(window_Width, window_Height); // Move multiple times
    CHECK_FALSE(player.GetPosition().x > window_Width - player.GetSize().x); // Should not exceed window width

    // Move Down beyond boundary
    player.down();
    for (int i = 0; i < 20; ++i) player.bound_Move(window_Width, window_Height); // Move multiple times
    CHECK_FALSE(player.GetPosition().y > window_Height - player.GetSize().y); // Should not exceed window height
}