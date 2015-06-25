/**
 * ========================
 * 
 * Filename: main.cpp
 * 
 * Author: Ceytix <ceytix@mailoo.org>
 * 
 * Description: main file which starts the game
 * 
 * Created: 29/04/15
 * =========================
 **/
 
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Tictactoe.cpp"
#include "functions.cpp"

using namespace std;

int main()
{	

	SDL_Init(SDL_INIT_VIDEO);
	
	do
	{
		Tictactoe game;
		game.play();
		SDL_Delay(1500);
	}
	while(playAgain());
	
	SDL_Quit();
	return 0;
}
