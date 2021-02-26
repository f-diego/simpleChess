CC=g++
CC2=x86_64-w64-mingw32-g++
CFLAGS=-Wall

SFMLPATH=X:/dev/SFML-2.5.1
SFMLFILES=-I "$(SFMLPATH)/include" -L "$(SFMLPATH)/lib/"
LIBd2=-lwinmm -lgdi32 -lopengl32 -lfreetype -lsfml-system-s-d -lsfml-window-s-d -lsfml-graphics-s-d
LIBd=-DSFML_STATIC -lsfml-graphics-s-d -lsfml-window-s-d -lsfml-system-s-d -lfreetype -lopengl32 -lgdi32 -lwinmm
LIB=-lsfml-graphics -lsfml-window -lsfml-system


all: game

game: main.cpp
	$(CC) $(CFLAGS) main.cpp Board.cpp $(SFMLFILES) $(LIBd) -o game.exe

run: game game.exe
	game.exe