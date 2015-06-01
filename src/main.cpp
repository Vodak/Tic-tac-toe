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
#include "Tictactoe.cpp"
#include "functions.cpp"

using namespace std;

int main()
{		
	do
	{
		Tictactoe game;
		game.play();
	}
	while(playAgain());
	
	return 0;
}
