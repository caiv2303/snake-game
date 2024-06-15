output = bin
source = src
include = -Iinclude
dependencias = -lftxui-screen -lftxui-dom -lftxui-component
flags = -std=c++2a $(dependencias) $(include)

run : $(output)/snake
	./$<

$(output)/snake : $(source)/main.cpp $(source)/Dibujo.hpp
	g++ -o $@ $< $(flags)

runPantalla : $(output)/pantalla
	./$<

$(output)/pantalla : $(source)/pantalla.cpp $(source)/Dibujo.hpp
	g++ -o $@ $< $(flags)