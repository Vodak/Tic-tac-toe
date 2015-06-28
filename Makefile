CC = g++
EXEC = Tic-tac-toe
LIBS = `sdl-config --cflags --libs` -lSDL -lSDLmain -lSDL_image
FLAGS = -Wall -Wextra

all:
	$(CC) src/main.cpp -o $(EXEC) $(LIBS) $(FLAGS)

clean:
	rm $(EXEC)
