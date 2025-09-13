#include "Monster.h"

void Monster::draw() const 
{
    if (state == MonsterSate::Disembodied) 
    {
        // Draw a semi-transparent monster when disembodied
        DrawRectangle(static_cast<int>(GetPosition().x), static_cast<int>(GetPosition().y),
                static_cast<int>(GetSize().x), static_cast<int>(GetSize().y), RAYWHITE);
        return;
    }
    else if (state == MonsterSate::Physical) 
    {
        // Draw a solid monster when physical
        DrawRectangle(static_cast<int>(GetPosition().x), static_cast<int>(GetPosition().y),
                static_cast<int>(GetSize().x), static_cast<int>(GetSize().y), DARKPURPLE);
    }
}

vector<Vector2> Monster::getPhysicalMoves(Earth& earth) const 
{
    vector<Vector2> possible_Moves;
    auto current_Pos = GetPosition();
    auto size = GetSize();
    auto move_Up = Vector2{current_Pos.x, current_Pos.y - 3*getSpeed()};
    auto move_Down = Vector2{current_Pos.x, current_Pos.y + 3*getSpeed()};
    auto move_Left = Vector2{current_Pos.x - 3*getSpeed(), current_Pos.y};
    auto move_Right = Vector2{current_Pos.x + 3*getSpeed(), current_Pos.y};

    // Check each potential move for collisions and add valid moves to the list, avoiding reversing direction
    if (!earth.isObjectCollide(Monster(move_Up, size)) && getDirection().y != 1) 
    {
        possible_Moves.push_back(Vector2{0, -1});
    }
    if (!earth.isObjectCollide(Monster(move_Down, size)) && getDirection().y != -1) 
    {
        possible_Moves.push_back(Vector2{0, 1});
    }
    if (!earth.isObjectCollide(Monster(move_Left, size)) && getDirection().x != 1) 
    {
        possible_Moves.push_back(Vector2{-1, 0});
    }
    if (!earth.isObjectCollide(Monster(move_Right, size)) && getDirection().x != -1) 
    {
        possible_Moves.push_back(Vector2{1, 0});
    }
    return possible_Moves;
}

float Monster::getPlayerDistance(const Player& player) const 
{
    auto Future_Pos = Vector2{GetPosition().x + getDirection().x * getSpeed(),
                              GetPosition().y + getDirection().y * getSpeed()};
    auto player_Pos = player.GetPosition();
    return std::sqrt(std::pow(player_Pos.x - Future_Pos.x, 2) + std::pow(player_Pos.y - Future_Pos.y, 2));
}

void Monster::setPhysicalDirection(const Player& player, Earth& earth) 
{
    auto monster_Pos = GetPosition();
    auto next_Direction = getDirection();
    auto current_Distance = getPlayerDistance(player);
    vector<Vector2> valid_Moves = getPhysicalMoves(earth);
    if (valid_Moves.empty()) 
    {
        setDirection(Vector2{-getDirection().x, -getDirection().y}); // No valid moves, reverse direction
        return;
    }
    for (const auto& move : valid_Moves) 
    {
        setDirection(move);
        if (getPlayerDistance(player) < current_Distance) 
        {
            next_Direction = move;
            current_Distance = getPlayerDistance(player);
        }
        else
        {
            setDirection(next_Direction); // Revert to previous direction if no improvement
        }
    }
}