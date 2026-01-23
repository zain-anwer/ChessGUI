#include <SDL2/SDL.h>
#include <iostream>
#include "chess/board.hpp"
#include "utils/audio.hpp"
#include "chess/dynamics.hpp"

#define SOUND_DELAY 25

using namespace std;

int main()
{
	SDL_Renderer* renderer;
	SDL_Window* window;

	ChessInterface interface;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		cerr << "SDL INITIALIZATION ERROR !\n";
	}
	
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

	window = SDL_CreateWindow("-- Chess --",0,0,640,480,SDL_WINDOW_SHOWN);

	renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	
	Board B1;

	bool running = true;

	Dynamics D(&interface);

	Audio audio;

	SDL_Point p;

	int sound_timer = 0;
	int select_result = 0;
	bool sound_timer_started = false;


	while(running)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				running = false;
			
			const Uint8* state = SDL_GetKeyboardState(NULL);
			
			if (state[SDL_SCANCODE_RETURN])
				SDL_Log("Help me!\n");
			
			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				if (event.button.button == SDL_BUTTON_LEFT)
				{
					sound_timer_started = true;
					cout << "Click Detected\n";

					SDL_GetMouseState(&p.x,&p.y);

					select_result = D.select(&p,B1);
					
					if (select_result == VALID_MOVE || select_result == VALID_CAPTURE)
						D.flipBoard(B1);
				}
			}				
		}

		if (select_result == SOURCE_SELECTION)
		{
			sound_timer_started = false;
			sound_timer = 0;
		}

		if (sound_timer_started)
			sound_timer++;

		if (select_result != SOURCE_SELECTION && sound_timer > SOUND_DELAY)
		{
			sound_timer_started = false;
			sound_timer = 0;
			audio.playSound(select_result);
		}

		B1.drawBoard(renderer);
	}
		
	SDL_DestroyRenderer(renderer);
			
	SDL_DestroyWindow(window);
		
	SDL_Quit();
				
	return 0;
}
