#include "Monster.h"

Monster::Monster(Vector2 pos, Vector2 size_, bool active, Vector2 dir)
        : Movable(pos, size_, active, dir), state(MonsterSate::Physical)
        {
            setSpeed(2.0f);
            locked_Moves.clear();
        }

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

void Monster::LockMoves() 
{
    Vector2 oppositeDir{ -getDirection().x, -getDirection().y };
    if (!isLockedMove(oppositeDir))
    {
        locked_Moves.push_back(LockedMove{oppositeDir, 30});
    } 
    else 
    {
        for (auto& locked_Move : locked_Moves) 
        {
            if (locked_Move.direction.x == oppositeDir.x && locked_Move.direction.y == oppositeDir.y) 
            {
                locked_Move.cooldown = 30; // Reset cooldown if already locked
                break;
            }
        }
    }
}

void Monster::unLockedMoves() 
{
    for (size_t i = 0; i < locked_Moves.size(); ++i) 
    {
        locked_Moves[i].cooldown--;
        if (locked_Moves[i].cooldown <= 0) 
        {
            locked_Moves.erase(locked_Moves.begin() + i);
            --i; // Adjust index after removal
        }
    }
}

bool Monster::isLockedMove(const Vector2& dir) const 
{
    for (const auto& locked_Move : locked_Moves) 
    {
        if (locked_Move.direction.x == dir.x && locked_Move.direction.y == dir.y) 
        {
            return true;
        }
    }
    return false;
}

vector<Vector2> Monster::getPhysicalMoves(Earth& earth) const 
{
    vector<Vector2> possible_Moves;
    auto current_Pos = GetPosition();
    Vector2 dirs[4] = { Vector2{0, -1}, Vector2{0, 1}, Vector2{-1, 0}, Vector2{1, 0} }; // Up, Down, Left, Right
    auto new_Pos = current_Pos;
    for (const auto& dir : dirs) 
    {
        if (isLockedMove(dir)) 
        {
            continue; // Skip locked moves
        }
        new_Pos = Vector2{ current_Pos.x + dir.x * getSpeed(), current_Pos.y + dir.y * getSpeed() };
        if (!earth.isObjectCollide(Monster{new_Pos, GetSize()}))
        {
            possible_Moves.push_back(dir);
        }
    }
    return possible_Moves;
}

float Monster::getDistanceToPlayer(const Player& player, const Vector2& testDirection) const 
{
    auto future_Pos = Vector2{GetPosition().x + testDirection.x * getSpeed(),
                              GetPosition().y + testDirection.y * getSpeed()};
    auto player_Pos = player.GetPosition();
    return std::sqrt(std::pow(player_Pos.x - future_Pos.x, 2) + std::pow(player_Pos.y - future_Pos.y, 2));
}

void Monster::setPhysicalDirection(const Player& player, Earth& earth) 
{
    vector<Vector2> valid_Moves = getPhysicalMoves(earth);
    if (valid_Moves.empty()) 
    {
        setDirection(Vector2{-getDirection().x, -getDirection().y}); // No valid moves, reverse direction
        locked_Moves.clear(); // Clear locked moves when reversing
        return;
    }

    Vector2 best_Direction = valid_Moves[0];
    auto best_Distance = getDistanceToPlayer(player, best_Direction); // Calculate distance for this direction
    auto current_Direction = getDirection();
    
    for (const auto& move : valid_Moves) 
    {
        float distance = getDistanceToPlayer(player, move); // Calculate distance without changing direction
        if (distance < best_Distance) 
        {
            best_Direction = move;
            best_Distance = distance;
        }
    }
    setDirection(best_Direction);
}

void Monster::chasePlayer(const Player& player, Earth& earth) 
{
    LockMoves();
    unLockedMoves();
    setPhysicalDirection(player, earth);
    Move();
}