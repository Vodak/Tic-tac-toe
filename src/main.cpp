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

using namespace std;

int main()
{
	
	char replay(' ');
	Tictactoe game;
		
	do
	{
		game.play();
		
		/** replay **/
		
		cout << "Do you want to play again ? yes(y) / no(n)" << endl;
		
		while(replay!='y' && replay!='n')
		{
			cin >> replay;
		}
		
	}while(replay=='y');
	
	return 0;
}
