CC = g++
EXEC = Tic-tac-toe
LIBS = `sdl-config --cflags --libs` -lSDL -lSDLmain -lSDL_image

all:
	$(CC) src/main.cpp -o $(EXEC) $(LIBS) 
