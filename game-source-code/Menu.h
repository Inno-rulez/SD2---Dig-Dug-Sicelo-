// Menu.h
#ifndef D1113FEB_573A_497C_8E32_4891F7E3E871
#define D1113FEB_573A_497C_8E32_4891F7E3E871

#include <raylib-cpp.hpp>
#include <string>

using namespace std;

class Menu {
    public:
        // Default values given here
        Menu(int width = 1200, int height = 800, int fps = 60, string t = "Dig Dug Project");
        ~Menu();

        void display();

    private:
        int screen_Width;
        int screen_Height;
        int target_FPS;
        std::string title;
        raylib::Window game_Window;
};

#endif /* D1113FEB_573A_497C_8E32_4891F7E3E871 */