// This code is adapted from: https://github.com/educ8s/Cpp-Pong-Game-Raylib

#include <raylib-cpp.hpp>
#include <iostream>
#include "Paddle.h"
using namespace raylib; // import the raylib-cpp namespace into the global namespace

// We have to scope the Color class to the definition in raylib-cpp.hpp because there is also a Color struct defined in raylib.h
raylib::Color green{38, 185, 154};
raylib::Color dark_green{20, 160, 133};
raylib::Color light_green{129, 204, 184};
raylib::Color yellow{243, 213, 91};

// Predefined raylib-cpp colours can be found here:
// https://robloach.github.io/raylib-cpp/classraylib_1_1_color.html#a3c177f10d10851fdf20d09fae83c8e19

int player_score = 0;
int cpu_score = 0;

class Ball
{
public:
    float x, y;
    int speed_x, speed_y;
    int radius;

    void Draw()
    {
        DrawCircle(x, y, radius, yellow);
    }

    void Update(Window &window)
    {
        x += speed_x;
        y += speed_y;

        if (y + radius >= window.GetHeight() || y - radius <= 0)
        {
            speed_y *= -1;
        }
        // Cpu wins
        if (x + radius >= window.GetWidth())
        {
            cpu_score++;
            ResetBall();
        }

        if (x - radius <= 0)
        {
            player_score++;
            ResetBall();
        }
    }

    void ResetBall()
    {
        x = GetScreenWidth() / 2;
        y = GetScreenHeight() / 2;

        int speed_choices[2] = {-1, 1};
        speed_x *= speed_choices[GetRandomValue(0, 1)];
        speed_y *= speed_choices[GetRandomValue(0, 1)];
    }
};

Ball ball;
Paddle player;
CpuPaddle cpu;

int main()
{
    const int screen_width = 1280;
    const int screen_height = 800;

    raylib::Window window(screen_width, screen_height, "My Pong Game!");

    window.SetTargetFPS(60);
    ball.radius = 20;
    ball.x = screen_width / 2;
    ball.y = screen_height / 2;
    ball.speed_x = 7;
    ball.speed_y = 7;

    player.width = 25;
    player.height = 120;
    player.x = screen_width - player.width - 10;
    player.y = screen_height / 2 - player.height / 2;
    player.speed = 6;

    cpu.height = 120;
    cpu.width = 25;
    cpu.x = 10;
    cpu.y = screen_height / 2 - cpu.height / 2;
    cpu.speed = 6;

    while (!window.ShouldClose())
    {
        window.BeginDrawing();

        // Updating

        ball.Update(window);
        player.Update(window);
        cpu.Update(ball.y, window);

        // Checking for collisions
        raylib::Rectangle player_paddle_bounds{player.x, player.y, player.width, player.height};

        raylib::Vector2 ball_position{ball.x, ball.y};

        if (player_paddle_bounds.CheckCollision(ball_position, ball.radius))
        {
            ball.speed_x *= -1;
        }

        raylib::Rectangle cpu_paddle_bounds{cpu.x, cpu.y, cpu.width, cpu.height};

        if (cpu_paddle_bounds.CheckCollision(ball_position, ball.radius))
        {
            ball.speed_x *= -1;
        }

        // Drawing
        window.ClearBackground(dark_green);

        raylib::Rectangle rect(screen_width / 2, 0, screen_width / 2, screen_height);
        rect.Draw(green);

        DrawCircle(screen_width / 2, screen_height / 2, 150, light_green);

        DrawLine(screen_width / 2, 0, screen_width / 2, screen_height, raylib::Color::White());

        ball.Draw();
        cpu.Draw();
        player.Draw();

        Text cpu_score_text{std::to_string(cpu_score), 80};
        cpu_score_text.Draw(raylib::Vector2{screen_width / 4 - 20, 20});

        Text player_score_text{std::to_string(player_score), 80};
        player_score_text.Draw(raylib::Vector2{3 * screen_width / 4 - 20, 20});

        window.EndDrawing();
    }

    return 0;
}