/**
 * ========================
 * 
 * Filename: functions.cpp
 * 
 * Author: Ceytix <ceytix@mailoo.org>
 * 
 * Description: Functions which make the code more attractive
 * 
 * Created: 01/06/15
 * =========================
 **/
 
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "functions.h"

using namespace std;

bool playAgain()
{
	char replay (' ');
	
	cout << "Do you want to play again ? yes(y) / no(n)" << endl;
		
	while(replay!='y' && replay!='n')
	{
		cin >> replay;
	}
	
	if(replay == 'y')
	{
		return true;
	}
	else
	{
		return false;
	}
}
