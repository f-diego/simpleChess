CC=g++ -g
CFLAGS=-Wall


INC=-ID:/msys64/mingw64/include/SDL2 -Dmain=SDL_main
LIB=-LD:/msys64/mingw64/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

all: ./build/sdl.exe

./build/sdl.exe: main.cpp sdl_app.cpp Board.cpp
	$(CC) -o "build/sdl.exe" main.cpp sdl_app.cpp Board.cpp $(INC) $(LIB)
	
run: ./build/sdl.exe
	./build/sdl.exe
