#ifndef A6BBD9D4_D6EC_4B66_AAF8_00A091776E24
#define A6BBD9D4_D6EC_4B66_AAF8_00A091776E24

#include <raylib-cpp.hpp>

/**
 * @brief 
 * 
 * @brief Base class for all game objects.
 * 
 * Represents a generic object in the game world with position and size.
 */
class GameObject 
{
    public:
        GameObject(raylib::Vector2 pos, raylib::Vector2 size_, bool active = true)
        : position(pos), size(size_), isActive(active) {}
        virtual ~GameObject() = default;

    private:
        raylib::Vector2 position;
        raylib::Vector2 size;
        bool isActive;
};

#endif /* A6BBD9D4_D6EC_4B66_AAF8_00A091776E24 */
