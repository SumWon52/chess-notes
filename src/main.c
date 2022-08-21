#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include <stdlib.h>
#include <stdio.h>

static SDL_bool wanted;
static SDL_Event event;

#include "config.h"


int main(void) {

	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;

	SDL_Init(INITFLAGS);
	SDL_CreateWindowAndRenderer(WINWIDTH, WINHEIGHT, WINFLAGS, &window, &renderer);

	const int linkNum = sizeof(eventLinks)/sizeof(EOL);


	wanted = SDL_TRUE;
	while (wanted) {
		while (SDL_PollEvent(&event)) {

			for (int i = 0; i < linkNum; i++) {
				if (eventLinks[i].chk_ev()) {
					eventLinks[i].action();
				}
			}
		}
	}
	

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return EXIT_SUCCESS;
}
