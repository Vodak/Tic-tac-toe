/**
 * ========================
 * 
 * Filename: Tictactoe.cpp
 * 
 * Author: Ceytix <ceytix@mailoo.org> ; IhFisk <ihfisk42@gmail.com>
 * 
 * Description: Tictactoe class functions
 * 
 * Created: 29/04/15
 * =========================
 **/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
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
	
	while(win()== 0) /** the game **/
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
	
	print(); //the map
	
	if(win() == 1)
	{
		if(twoPlayers)
		{
			cout << "The winner is the first player" << endl;
		}
		else
		{
			cout << "The winner is the player" << endl;
		}
	}
	else if(win() == 2)
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
	
	else
	{
		cout << "Equality" << endl;
	}
	
}

/*******
* turn *
*******/

void Tictactoe::turn()
{
	print(); //the map
	
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
		} while(line<0 || line>2);
		
		cout << "Enter the column:" << endl;
		
		do
		{
			cin >> column;
			column--;
		} while(column<0 || column>2);

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

    if(map[0][0] == map[0][1] && map[0][0] == map[0][2] && map[0][0] != '*') /* Test for every posibilities to win */
    {
        if(map[0][0] == 'X')
            return 1;
            
        else if(map[0][0] == 'O')
            return 2;
    }

    else if(map[1][0] == map[1][1] && map[1][0] == map[1][2] && map[1][0] != '*')
    {
        if(map[1][0] == 'X')
            return 1;
            
        else if(map[1][0] == 'O')
            return 2;
    }
    
    else if(map[2][0] == map[2][1] && map[2][0] == map[2][2] && map[2][0] != '*')
    {
        if(map[2][0] == 'X')
            return 1;
            
        else if(map[2][0] == 'O')
            return 2;
            
    }
    
    else if(map[0][0] == map[1][0] && map[0][0] == map[2][0] && map[0][0] != '*')
    {
        if(map[0][0] == 'X')
            return 1;
            
        else if(map[0][0] == 'O')
            return 2;
            
    }
    
    else if(map[0][1] == map[1][1] && map[0][1] == map[2][1] && map[0][1] != '*')
    {
        if(map[0][1] == 'X')
            return 1;
            
        else if(map[0][1] == 'O')
            return 2;
          
    }
    
    else if(map[0][2] == map[1][2] && map[0][2] == map[2][2] && map[0][2] != '*')
    {
       if(map[0][2] == 'X')
            return 1;
            
        else if(map[0][2] == 'O')
            return 2;
            
    }
    
    else if(map[2][0] == map[1][1] && map[2][0] == map[0][2] && map[2][0] != '*')
    {
        if(map[2][0] == 'X')
            return 1;
            
        else if(map[2][0] == 'O')
            return 2;

    }
    
    else if(map[0][0] == map[1][1] && map[0][0] == map[2][2] && map[0][0] != '*')
    {
        if(map[0][0] == 'X')
            return 1;
            
        else if(map[0][0] == 'O')
            return 2;
 
    }
    
    else if(map[0][0] != '*' && map[0][1] != '*' && map[0][2] != '*' && map[1][0] != '*' && map[1][1] != '*' && map[1][2] != '*' && map[2][0] != '*' && map[2][1] != '*' && map[2][2] != '*')
    {
    	return 3;
    }
    
    else return 0;
}

/*****
* AI *
*****/

void Tictactoe::AI()
{
	    /* This is a scan for every possibilities of win and counter possibilities for the enemy of win */

    if(map[0][0] == map[0][1] && map[0][0] == 'O' && map[0][2] == '*')
    {
        map[0][2] = 'O';
    }

    else if(map[0][1] == map[0][2] && map[0][1] == 'O' && map[0][0] == '*')
    {
        map[0][0] = 'O';
    }

    else if(map[1][0] == map[1][1] && map[1][0] == 'O' && map[1][2] == '*')
    {
        map[1][2] = 'O';
    }

    else if(map[1][1] == map[1][2] && map[1][1] == 'O' && map[1][0] == '*')
    {
        map[1][0] = 'O';
    }

    else if(map[2][0] == map[2][1] && map[2][0] == 'O' && map[2][2] == '*')
    {
        map[2][2] = 'O';
    }

    else if(map[2][1] == map[2][2] && map[2][1] == 'O' && map[2][0] == '*')
    {
        map[2][0] = 'O';
    }

    else if(map[0][0] == map[1][0] && map[0][0] == 'O' && map[2][0] == '*')
    {
        map[2][0] = 'O';
    }

    else if(map[1][0] == map[2][0] && map[1][0] == 'O' && map[0][0] == '*')
    {
        map[0][0] = 'O';
    }

    else if(map[0][1] == map[1][1] && map[0][1] == 'O' && map[2][1] == '*')
    {
        map[2][1] = 'O';
    }

    else if(map[1][1] == map[2][1] && map[1][1] == 'O' && map[0][1] == '*')
    {
        map[0][1] = 'O';
    }

    else if(map[0][1] == map[2][1] && map[0][1] == 'O' && map[1][1] == '*')
    {
        map[1][1] = 'O';
    }

    else if(map[1][2] == map[2][2] && map[1][2] == 'O' && map[0][2] == '*')
    {
         map[0][2] = 'O';
    }

    else if(map[0][0] == map[0][2] && map[0][0] == 'O' && map[0][1] == '*')
    {
        map[0][1] = 'O';
    }

    else if(map[1][0] == map[1][2] && map[1][0] == 'O' && map[1][1] == '*')
    {
        map[1][1] = 'O';
    }

    else if(map[2][0] == map[2][2] && map[2][0] == 'O' && map[2][1] == '*')
    {
        map[2][1] = 'O';
    }

    else if(map[0][0] == map[1][1] && map[0][0] == 'O' && map[2][2] == '*')
    {
        map[2][2] = 'O';
    }

    else if(map[1][1] == map[2][2] && map[1][1] == 'O' && map[0][0] == '*')
    {
        map[0][0] = 'O';
    }

    else if(map[0][0] == map[2][2] && map[0][0] == 'O' && map[1][1] == '*')
    {
        map[1][1] = 'O';
    }

    else if(map[2][0] == map[1][1] && map[2][0] == 'O' && map[0][2] == '*')
    {
        map[0][2] = 'O';
    }

    else if(map[1][1] == map[0][2] && map[1][1] == 'O' && map[2][0] == '*')
    {
        map[2][0] = 'O';
    }

    else if(map[2][0] == map[0][2] && map[2][0] == 'O' && map[1][1] == '*')
    {
        map[1][1] = 'O';
    }

    else if(map[0][0] == map[0][2] && map[0][0] == 'O' && map[0][1] == '*')
    {
        map[0][1] = 'O';
    }

    else if(map[0][0] == map[2][0] && map[0][0] == 'O' && map[1][0] == '*')
    {
        map[1][0] = 'O';
    }

    else if(map[0][2] == map[2][2] && map[0][2] == 'O' && map[1][2] == '*')
    {
        map[1][2] = 'O';
    }
    
    else if(map[0][0] == map[0][1] && map[0][0] == 'X' && map[0][2] == '*')
    {
        map[0][2] = 'O';
    }

    else if(map[0][1] == map[0][2] && map[0][1] == 'X' && map[0][0] == '*')
    {
        map[0][0] = 'O';
    }

    else if(map[1][0] == map[1][1] && map[1][0] == 'X' && map[1][2] == '*')
    {
        map[1][2] = 'O';
    }

    else if(map[1][1] == map[1][2] && map[1][1] == 'X' && map[1][0] == '*')
    {
        map[1][0] = 'O';
    }

    else if(map[2][0] == map[2][1] && map[2][0] == 'X' && map[2][2] == '*')
    {
        map[2][2] = 'O';
    }

    else if(map[2][1] == map[2][2] && map[2][1] == 'X' && map[2][0] == '*')
    {
        map[2][0] = 'O';
    }

    else if(map[0][0] == map[1][0] && map[0][0] == 'X' && map[2][0] == '*')
    {
        map[2][0] = 'O';
    }

    else if(map[1][0] == map[2][0] && map[1][0] == 'X' && map[0][0] == '*')
    {
        map[0][0] = 'O';
    }

    else if(map[0][1] == map[1][1] && map[0][1] == 'X' && map[2][1] == '*')
    {
        map[2][1] = 'O';
    }

    else if(map[1][1] == map[2][1] && map[1][1] == 'X' && map[0][1] == '*')
    {
        map[0][1] = 'O';
    }

    else if(map[0][1] == map[2][1] && map[0][1] == 'X' && map[1][1] == '*')
    {
        map[1][1] = 'O';
    }

    else if(map[1][2] == map[2][2] && map[1][2] == 'X' && map[0][2] == '*')
    {
         map[0][2] = 'O';
    }

    else if(map[0][0] == map[0][2] && map[0][0] == 'X' && map[0][1] == '*')
    {
        map[0][1] = 'O';
    }

    else if(map[1][0] == map[1][2] && map[1][0] == 'X' && map[1][1] == '*')
    {
        map[1][1] = 'O';
    }

    else if(map[2][0] == map[2][2] && map[2][0] == 'X' && map[2][1] == '*')
    {
        map[2][1] = 'O';
    }

    else if(map[0][0] == map[1][1] && map[0][0] == 'X' && map[2][2] == '*')
    {
        map[2][2] = 'O';
    }

    else if(map[1][1] == map[2][2] && map[1][1] == 'X' && map[0][0] == '*')
    {
        map[0][0] = 'O';
    }

    else if(map[0][0] == map[2][2] && map[0][0] == 'X' && map[1][1] == '*')
    {
        map[1][1] = 'O';
    }

    else if(map[2][0] == map[1][1] && map[2][0] == 'X' && map[0][2] == '*')
    {
        map[0][2] = 'O';
    }

    else if(map[1][1] == map[0][2] && map[1][1] == 'X' && map[2][0] == '*')
    {
        map[2][0] = 'O';
    }

    else if(map[2][0] == map[0][2] && map[2][0] == 'X' && map[1][1] == '*')
    {
        map[1][1] = 'O';
    }

    else if(map[0][0] == map[0][2] && map[0][0] == 'X' && map[0][1] == '*')
    {
        map[0][1] = 'O';
    }

    else if(map[0][0] == map[2][0] && map[0][0] == 'X' && map[1][0] == '*')
    {
        map[1][0] = 'O';
    }

    else if(map[0][2] == map[2][2] && map[0][2] == 'X' && map[1][2] == '*')
    {
        map[1][2] = 'O';
    }

        /* End of the scan */

    else
    {
        /* Now the AI will play on the corners */
        
        bool corner = false;
		do
		{
			int choice = rand()%4+1;
		
			if(map[0][0] == '*' && choice == 1)
			{
			    map[0][0] = 'O';
			    corner = true;
			}

		    else if(map[2][0] == '*' && choice == 2)
		    {
		        map[2][0] = 'O';
			    corner = true;
		    }

		    else if(map[2][2] == '*' && choice == 2)
		    {
		        map[2][2] = 'O';
		        corner = true;
		    }

		    else if(map[0][2] == '*' && choice == 2)
		    {
		        map[0][2] = 'O';
		        corner = true;
		    }
		}
		while(!corner);
    }
	
	playerTurn = 1;
}

/********
* print *
********/

void Tictactoe::print()
{
	SDL_Surface *screen = NULL,*background = NULL, *player = NULL, *circle = NULL, *cross = NULL;
	SDL_Rect backgroundPos, playerPos, circlePos, crossPos;
	
	screen = SDL_SetVideoMode(800, 800, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	background = IMG_Load("pictures/background.png");
	circle = IMG_Load("pictures/circle.png");
	cross = IMG_Load("pictures/cross.png");
	if(playerTurn == 1)
	{
		player = IMG_Load("pictures/player1.png");
	}
	else
	{
		player = IMG_Load("pictures/player2.png");
	}
	
	backgroundPos.x = 0;
	backgroundPos.y = 0;
	
	playerPos.x = 5;
	playerPos.y = 755;
	
	SDL_BlitSurface(background, NULL, screen, &backgroundPos);
	SDL_BlitSurface(player, NULL, screen, &playerPos);
	
	for(int i=0; i<=2; i++)
	{
		for(int j=0; j<=2; j++)
		{
			if(map[i][j] == 'O')
			{
				circlePos.x = 280*j;
				circlePos.y = 280*i;
				SDL_BlitSurface(circle, NULL, screen, &circlePos);
			}
			else if(map[i][j] == 'X')
			{
				crossPos.x = 280*j;
				crossPos.y = 280*i;
				SDL_BlitSurface(cross, NULL, screen, &crossPos);
			}
		}
	}
	
	SDL_Flip(screen);
	
	SDL_FreeSurface(player);
	SDL_FreeSurface(circle);
	SDL_FreeSurface(cross);
	SDL_FreeSurface(background);
	SDL_FreeSurface(screen);
}
