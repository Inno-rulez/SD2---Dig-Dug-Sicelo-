// Menu.h
#ifndef D1113FEB_573A_497C_8E32_4891F7E3E871
#define D1113FEB_573A_497C_8E32_4891F7E3E871

#include <raylib-cpp.hpp>
#include <string>

using namespace std;

enum class game_States
{
    Splash_Screen,
    Playing,
    Paused,
    Instructions,
    Game_Over
};


/**
 * @brief Represents the main menu for the Dig Dug Project game.
 * 
 * Handles window creation, display, and configuration settings.
 */
class Menu
{
    public:
        /**
         * @brief Constructs a Menu object with specified window dimensions, FPS, and title.
         * 
         * This constructor initializes the game window with the given width, height, target FPS, and title.
         * @param width The width of the game window.
         * @param height The height of the game window.
         * @param fps The target frames per second.
         * @param t The title of the game window.
         */
        Menu(int width = 1200, int height = 800, int fps = 60, string t = "Dig Dug Project");
        /// @brief 
        ~Menu();

        /**
         * @brief Displays the main menu window and handles menu interactions.
         */
        void display();

    private:
        int screen_Width;
        int screen_Height;
        int target_FPS;
        std::string title;
        raylib::Window game_Window;
        game_States current_State;
};

#endif /* D1113FEB_573A_497C_8E32_4891F7E3E871 */