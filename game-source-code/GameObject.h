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
        /**
         * @brief 
         * 
         * @brief Constructs a new GameObject.
         * @param pos The position of the object in the game world.
         * @param size_ The size of the object.
         * @param active Whether the object is active (default: true).
         */
        GameObject(raylib::Vector2 pos, raylib::Vector2 size_, bool active = true)
        : position(pos), size(size_), isActive(active) {}
        virtual ~GameObject() = default;
        /**
         * @brief 
         * 
         * @brief Gets the position of the game object.
         * @return The position as a raylib::Vector2.
         */
        raylib::Vector2 GetPosition() const { return position; }
        /**
         * @brief 
         * 
         * @brief Gets the size of the game object.
         * @return The size as a raylib::Vector2.
         */
        raylib::Vector2 GetSize() const { return size; }
        void deactivate() { isActive = false; }
        bool getActive() const { return isActive; }

    private:
        raylib::Vector2 size;
        bool isActive;

    protected:
        /**
         * @brief 
         * 
         * @brief The position of the game object in the game world.
         */
        raylib::Vector2 position;
};

#endif /* A6BBD9D4_D6EC_4B66_AAF8_00A091776E24 */
