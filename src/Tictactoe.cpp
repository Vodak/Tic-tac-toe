/**
 * ========================
 * 
 * Filename: Tictactoe.cpp
 * 
 * Author: Ceytix <ceytix@mailoo.org>
 * 
 * Description: Tictactoe class functions
 * 
 * Created: 29/04/15
 * =========================
 **/
 
#include <ctime>
#include <cstdlib>
#include <string>
#include "Tictactoe.h"

using namespace std;

/**************
* constructor *
**************/

Tictactoe::Tictactoe()
{
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			map[i][j] = '*';
		}
	}
	
	srand(time(0)); // the player who begins is randomly chosen
	playerTurn = rand()%2 + 1;
}

/*************
* destructor *
*************/

Tictactoe::~Tictactoe()
{
	//nothing
}

/*******
* play *
*******/
	
void Tictactoe::play()
{
	bool twoPlayers = multi();
	
	while(win()==0) /** the game **/
	{
		if(twoPlayers)
		{
			turn();
		}
		else
		{
			if(playerTurn == 1)
			{
				turn();
			}
			else
			{
				AI();
			}
		}
	}
	
	if(win() == 1)
	{
		cout << "The winner is the first player" << endl;
	}
	else
	{
		if(twoPlayers)
		{
			cout << "The winner is the second player" << endl;
		}
		else
		{
			cout << "The winner is the Artificial Intelligence" << endl;
		}
	}
}

/*******
* turn *
*******/

void Tictactoe::turn()
{
	cout << "  1 2 3\n" << endl;
	cout << "1 " << map[0][0] << ' ' << map[0][1] << ' ' << map[0][2] << '\n' << endl;
	cout << "2 " << map[1][0] << ' ' << map[1][1] << ' ' << map[1][2] << '\n' << endl;
	cout << "3 " << map[2][0] << ' ' << map[2][1] << ' ' << map[2][2] << endl;
	
	if(playerTurn==1)
	{
		cout << "You are P1 - You have X" << endl;
	}
	else
	{
		cout << "You are P2 - You have O" << endl;
	}
	
	int column(0), line(0);
	
	do
	{
		cout << "Where do you want to play ?\nEnter the line:" << endl;
	
		do
		{
			cin >> line;
			line--;
		}while(line<0 || line>2);
		
		cout << "Enter the column:" << endl;
		
		do
		{
			cin >> column;
			column--;
		}while(column<0 || column>2);

		if(map[line][column] != '*')
		{
			cout << "It's not possible" << endl;
		}
		
	} while(map[line][column] != '*');
	
	if(playerTurn==1)
	{
		map[line][column] = 'X';
		playerTurn = 2;
	}
	else
	{
		map[line][column] = 'O';
		playerTurn = 1;
	}
}

/********
* multi *
********/

bool Tictactoe::multi()
{
	cout << "Do you want to play against a player(p) or against an AI(a) ?" << endl;
	
	char choice(' ');
	while(choice!='p' && choice!='a')
	{
		cin >> choice;
	}
	
	if(choice == 'p')
	{
		return true;
	}
	else 
	{
		return false;
	}
}

/********
* Win *
********/

int Tictactoe::win()
{

    if(map[0][0] == map[0][1] && map[0][0] == map[0][2])
    {
        if(map[0][0] == 'X')
            return 1;
            
        else if(map[0][0] == 'O')
            return 2;
            
        else return 0;
    }

    else if(map[1][0] == map[1][1] && map[1][0] == map[1][2])
    {
        if(map[1][0] == 'X')
            return 1;
            
        else if(map[1][0] == 'O')
            return 2;
            
        else return 0;
    }
    
    else if(map[2][0] == map[2][1] && map[2][0] == map[2][2])
    {
        if(map[2][0] == 'X')
            return 1;
            
        else if(map[2][0] == 'O')
            return 2;
            
        else return 0;
    }
    
    else if(map[0][0] == map[1][0] && map[0][0] == map[2][0])
    {
        if(map[0][0] == 'X')
            return 1;
            
        else if(map[0][0] == 'O')
            return 2;
            
        else return 0;
    }
    
    else if(map[0][1] == map[1][1] && map[0][1] == map[2][1])
    {
        if(map[0][1] == 'X')
            return 1;
            
        else if(map[0][1] == 'O')
            return 2;
            
        else return 0;
    }
    
    else if(map[0][2] == map[1][2] && map[0][2] == map[2][2])
    {
       if(map[0][2] == 'X')
            return 1;
            
        else if(map[0][2] == 'O')
            return 2;
            
        else return 0; 
    }
    
    else if(map[2][0] == map[1][1] && map[2][0] == map[0][2])
    {
        if(map[2][0] == 'X')
            return 1;
            
        else if(map[2][0] == 'O')
            return 2;
            
        else return 0;
    }
    
    else if(map[0][0] == map[1][1] && map[0][0] == map[2][2])
    {
        if(map[0][0] == 'X')
            return 1;
            
        else if(map[0][0] == 'O')
            return 2;
            
        else return 0;
    }
    
    else return 0;   
}

/*****
* AI *
*****/

void Tictactoe::AI()
{
	
}
