#include <iostream>
#include <ftxui/screen/screen.hpp>
#include <ftxui/dom/elements.hpp>
#include <thread>
#include <chrono>


using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[])
{
    int x = 0;
    while (true)
    {
        x++;
        Element dibujo = vbox(
            {
                text("            / . . |") | move_to(x, 5),
                text("            |  ---< ") | move_to(x, 6),
                text("             |  / ") | move_to(x, 7),
                text("   __________/ / ") | move_to(x, 8),
                text("-=:___________/ ") | move_to(x, 9),
            });

        Screen pantalla = Screen::Create(Dimension::Full());
        Render(pantalla, dibujo);
        pantalla.Print();
        cout << pantalla.ResetPosition();
        this_thread::sleep_for(chrono::milliseconds(100));
    }

    return 0;
}