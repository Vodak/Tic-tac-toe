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
	
	SDL_Surface *screen, *background;
	SDL_Rect backgroundPos;
	SDL_Event replayEvent;
	
	screen = SDL_SetVideoMode(800, 800, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	background = IMG_Load("pictures/retry.png");

	backgroundPos.x = 0;
	backgroundPos.y = 0;
	
	bool replay;
	bool quit (false);
	
	while(!quit)
	{
		SDL_WaitEvent(&replayEvent);
		
		switch(replayEvent.type)
		{
			case SDL_KEYDOWN:
				if(replayEvent.key.keysym.sym == SDLK_ESCAPE)
				{
					replay = false;
					quit = true;
				}
			break;
			
			case SDL_QUIT:
				replay = false;
				quit = true;
			break;
			
			case SDL_MOUSEBUTTONDOWN:
				if(replayEvent.button.button == SDL_BUTTON_LEFT)
				{
					if(replayEvent.button.x >= 150 && replayEvent.button.x <= 650 && replayEvent.button.y >= 360 && replayEvent.button.y <= 440) /** yes **/
					{
						replay = true;
						quit = true;
					}
					if(replayEvent.button.x >= 150 && replayEvent.button.x <= 650 && replayEvent.button.y >= 511 && replayEvent.button.y <= 591) /** no **/
					{
						replay = false;
						quit = true;
					}
				}
			break;
		}
		
		SDL_BlitSurface(background, 0, screen, &backgroundPos);
		SDL_Flip(screen);
	}
	
	SDL_FreeSurface(background);
	return replay;
}
