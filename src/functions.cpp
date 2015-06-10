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
	SDL_Delay(1500);
	
	SDL_Surface *screen, *background;
	SDL_Rect backgroundPos;
	SDL_Event replayEvent;
	
	screen = SDL_SetVideoMode(800, 800, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	background = IMG_Load("pictures/retry.png");

	backgroundPos.x = 0;
	backgroundPos.y = 0;
	
	while(1)
	{
		SDL_WaitEvent(&replayEvent);
		
		switch(replayEvent.type)
		{
			case SDL_KEYDOWN:
				if(replayEvent.key.keysym.sym == SDLK_ESCAPE)
				{
					return false;
				}
			break;
			
			case SDL_QUIT:
				return false;
			break;
			
			case SDL_MOUSEBUTTONDOWN:
				if(replayEvent.button.button == SDL_BUTTON_LEFT)
				{
					if(replayEvent.button.x >= 150 && replayEvent.button.x <= 650 && replayEvent.button.y >= 360 && replayEvent.button.y <= 440) /** yes **/
					{
						return true;
					}
					if(replayEvent.button.x >= 150 && replayEvent.button.x <= 650 && replayEvent.button.y >= 511 && replayEvent.button.y <= 591) /** no **/
					{
						return false;
					}
				}
			break;
		}
		
		SDL_BlitSurface(background, NULL, screen, &backgroundPos);
		SDL_Flip(screen);
	}
}
