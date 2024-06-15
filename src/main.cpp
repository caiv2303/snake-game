#include <iostream>
#include <ftxui/screen/screen.hpp>
#include <ftxui/dom/elements.hpp>
#include <thread>
#include <string>
#include <fstream>
#include <Dibujo.hpp>
#include <chrono>
#include <conio.h> // Para la función _kbhit() y _getch() en Windows

using namespace std;
using namespace ftxui;

int main (int argc, char const *argv[])
{
    // Inicializar objeto Dibujo con la ruta al archivo de texto.
    Dibujo snake("./assets/images/snake.txt");

    int fotograma = 0;
    bool running = true;

    while(running)
    {
        // Dormir el hilo principal por 100 milisegundos.
        this_thread::sleep_for(chrono::milliseconds(100));
        fotograma++;

        // Crear el elemento del spinner.
        Element personaje = spinner(21, fotograma) | bold | color(Color::Purple) | bgcolor(Color::White);
        
        // Crear el elemento del dibujo.
        Element dibujo = hbox({personaje, snake.GetElement()});
        
        // Crear y renderizar la pantalla.
        Screen pantalla = Screen::Create(Dimension::Full());
        Render(pantalla, dibujo);
        pantalla.Print();
        cout << pantalla.ResetPosition();

        // Salir del bucle si se presiona una tecla.
        if (_kbhit())
        {
            char ch = _getch();
            if (ch == 'q' || ch == 'Q')  // Presionar 'q' o 'Q' para salir
            {
                running = false;
            }
        }
    }
    
    return EXIT_SUCCESS;
}