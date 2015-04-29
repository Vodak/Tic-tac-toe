#include <iostream>
#include "Tictactoe.cpp"

using namespace std;

int main()
{
	
	char replay(' ');
		
	do
	{
		Tictactoe game;
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
