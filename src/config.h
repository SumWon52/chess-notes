#pragma once

#include "EOL.h"

#define INITFLAGS SDL_INIT_VIDEO // flags to be passed to sdl, just make sure to leave what is there already
#define WINFLAGS  0 // set to SDL_WINDOW_FULLSCREEN to be in fullscreen

#define WINHEIGHT 500 // window height (start)
#define WINWIDTH  700 // window width (start)




static inline int close_chk_ev() {
	return event.type == SDL_QUIT;
}

static inline void close() {
	wanted = SDL_FALSE;
}


const EOL eventLinks[] = {
	{ close_chk_ev, close } // close the program when asked to
};
