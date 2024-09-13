#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <raylib-cpp.hpp>
#include "Paddle.h"
#include <iostream>

TEST_CASE("CpuPaddle's position remains unchanged when trying to move beyond the top of the screen")
{
    // Arrange
    const int screen_width = 1280;
    const int screen_height = 800;
    raylib::Window window(screen_width, screen_height, "My Pong Game!");

    CpuPaddle paddle;
    paddle.height = 120;
    paddle.speed = 6;
    paddle.y = 0; // place paddle at the top of the screen

    int ball_position = 20; // make the paddle move up to track the ball position

    // Act
    paddle.Update(ball_position, window);

    // Assert
    CHECK(paddle.y == 0);
}

TEST_CASE("CpuPaddle's postion remains unchanged when trying to move beyond the bottom of the screen")
{
    // Arrange
    const int screen_width = 1280;
    const int screen_height = 800;
    raylib::Window window(screen_width, screen_height, "My Pong Game!");

    CpuPaddle paddle;
    paddle.height = 120;
    paddle.speed = 6;
    paddle.y = 680; // place paddle at the bottom of the screen

    int ball_position = 800; // make the paddle move down to track the ball position

    // Act
    paddle.Update(ball_position, window);

    // Assert
    CHECK(paddle.y == 680);
}