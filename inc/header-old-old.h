
#ifndef HEADER_H
#define HEADER_H

// ---------------------------
//#include "SDL2/SDL.h"
//#include "SDL2/SDL_image.h"
//#include "SDL2/SDL_ttf.h"
//#include "SDL2/SDL_mixer.h"
// ---------------------------
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
//#include <SDL2/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2/SDL_timer.h>


#include <stdbool.h>
#include <unistd.h>
#include <errno.h>

#define CARDS_ARR_NUMBER (30) // be careful with seg_fault
#define WINDOW_WIDTH (950)
#define WINDOW_HEIGHT (850)

#define LEN_ARR (16)
#define OPN_CRDS_NBR (3)


#define ANIMALS (1)
#define DISSTRS (2)
#define FOOD (3)
#define LIGHT (4)
#define MUSIC (5)

void mx_errorexit(char *str);
void mx_printerror(char *str);

typedef struct card {
	bool	open;
	bool	print;
	int 	type;
	int 	id;
	SDL_Surface	*face;
	SDL_Rect	pos;
} cards;

typedef struct player {
	int 	score;
	int 	try;
} plyr;

typedef struct application {
	char 	**str;
	SDL_Window *win;
	SDL_Surface *srf;
	SDL_Surface *close;
	plyr	plr1;
	plyr	plr2;
	cards	*arr;
//	cards	*rand;

} app;

char 	**mx_list_resourses(app *game);
void 	mx_set_start_val(app *game);
void	mx_app_loop(app *game);
void	mx_turn_over_card(app *game, int x, int y);
void	window_cards_update(app *game);

#endif
