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
	SDL_Event event;
	
	screen = SDL_SetVideoMode(800, 800, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	SDL_WM_SetCaption("Tic-Tac-Toe by Vodak", 0);
	background = IMG_Load("pictures/retry.png");

	backgroundPos.x = 0;
	backgroundPos.y = 0;
	
	bool replay;
	bool quit (false);
	
	while(!quit)
	{
		SDL_PollEvent(&event);
		
		switch(event.type)
		{
			case SDL_KEYDOWN:
				if(event.key.keysym.sym == SDLK_ESCAPE)
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
				if(event.button.button == SDL_BUTTON_LEFT)
				{
					if(event.button.x >= 150 && event.button.x <= 650 && event.button.y >= 360 && event.button.y <= 440) /** YES **/
					{
						replay = true;
						quit = true;
					}
					if(event.button.x >= 150 && event.button.x <= 650 && event.button.y >= 511 && event.button.y <= 591) /** NO **/
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
