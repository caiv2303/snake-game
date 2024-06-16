output = bin
source = src
include_dir = include
assets_dir = assets
dependencias = -lftxui-screen -lftxui-dom -lftxui-component
flags = -std=c++2a $(dependencias) -I$(include_dir)

all: $(output)/snake

run_snake: $(output)/snake
	./$<

$(output)/snake: $(source)/main.cpp $(source)/Dibujo.hpp | $(output)
	g++ -o $@ $(source)/main.cpp $(flags)

$(output):
	mkdir -p $(output)

$(source)/Dibujo.hpp:

clean:
	rm -rf $(output)/*

.PHONY: all run_snake clean