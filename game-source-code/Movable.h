#ifndef B365A16D_2B9C_4A96_8D8A_1D870DD49F24
#define B365A16D_2B9C_4A96_8D8A_1D870DD49F24

#include <raylib-cpp.hpp>
#include "GameObject.h"
#include <cmath>

/**
 * @brief Represents a movable game object that can change position and direction.
 * 
 * The Movable class extends GameObject and adds functionality for movement,
 * including direction and speed. It provides methods to move the object
 * up, down, left, and right, as well as to set its speed.
 */
class Movable : public GameObject
{
    public:
        /**
         * @brief 
         * 
         * @brief Constructs a Movable object.
         * @param pos The position of the object.
         * @param size_ The size of the object (default is {20, 20}).
         * @param active Whether the object is active (default is true).
         * @param dir The initial direction vector (default is {0, 0}).
         */
        Movable(Vector2 pos, Vector2 size_ = Vector2{20, 20}, bool active = true, Vector2 dir = Vector2{0,0})
        : GameObject(pos, size_, active), direction(dir), speed(0.0f) {}
        /**
         * @brief Moves the object upwards by updating its direction.
         */
        void up();

        /** @brief Moves the object downwards by updating its direction.
         */
        void down();

        /**
         * @brief Moves the object to the left by updating its direction.
         */
        void left();

        /**
         * @brief Moves the object to the right by updating its direction.
         */
        void right();

        /**
         * @brief Stops the object's movement by resetting its direction.
         */
        void stop();

        /**
         * @brief Set the Direction object
         * 
         * @param dir 
         */
        void setDirection(Vector2 dir);

        /**
         * @brief Sets the speed of the object.
         * @param s The new speed value.
         */
        void setSpeed(float s) { speed = s; }
        /**
         * @brief Gets the current speed of the object.
         * @return The speed as a float.
         */
        float getSpeed() const { return speed; }
        /**
         * @brief 
         * 
         * @brief Moves the object based on its direction and speed.
         */
        void Move();
        /**
         * @brief 
         * 
         * @brief Draws the movable object.
         * 
         * This is a pure virtual function that must be implemented by derived classes
         * to handle the rendering of the movable object.
         */
        virtual void draw() const = 0;
        virtual ~Movable() = default;

    private:
        Vector2 direction;
        float speed;
};

#endif /* B365A16D_2B9C_4A96_8D8A_1D870DD49F24 */
