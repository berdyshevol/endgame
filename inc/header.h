
#ifndef HEADER_H
#define HEADER_H

// ---------------------------
//#include "SDL2/SDL.h"
//#include "SDL2/SDL_image.h"
//#include "SDL2/SDL_ttf.h"
//#include "SDL2/SDL_mixer.h"
// ---------------------------
//#include <SDL2/SDL.h>
//#include <SDL2_image/SDL_image.h>
//#include <SDL2/SDL_image.h>
//#include <SDL2/SDL_ttf.h>

//#include <SDL2/SDL_timer.h>
//#include "SDL2/SDL.h"
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2_mixer/SDL_mixer.h>
//#include "SDL_mixer.h"
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <stddef.h>
#include <stdlib.h>

#define CARDS_ARR_NUMBER (30) // be careful with seg_fault
#define WINDOW_WIDTH (1600)
#define WINDOW_HEIGHT (1200)
#define GAME_OVER_H (100)

#define CHOOSE_Y (300)
#define txt0_y ()

//#define OFFSET_Y (70)
//#define OFFSET_X (50)
//#define LEN_ARR (16)
//#define OPN_CRDS_NBR (3)
#define NUMBER_OF_PLAYERS (2)
//#define SECONDS_OPEN (3000)
#define MENU_BTN_SIZE_X (100)
#define MENU_BTN_SIZE_Y (100)
#define ANIMALS (1)
#define DISSTRS (2)
#define FOOD (3)
#define LIGHT (4)
#define MUSIC (5)

void mx_errorexit(char *str);
void mx_printerror(char *str);
typedef struct _Mix_Music Mix_Music;
typedef struct Mix_Chunk Mix_Chunk;

typedef struct card {
	bool	open;
	bool	print;
	int 	type;
	int 	id;
	SDL_Surface	*face;
	SDL_Rect	pos;
} cards;

typedef struct  menu {
	SDL_Surface	*txt0;
	SDL_Surface	*txt1;
	SDL_Surface	*txt2;
	SDL_Surface	*txt3;
	SDL_Surface	*choose_level;
	TTF_Font *font;
	TTF_Font *choose_level_font;

	bool on_txt0;
	bool on_txt1;
	bool on_txt2;
	bool on_txt3;
	bool anim;

	double t0;
	double t1;
	double t2;
	double t3;

	int y0;
	int y1;
	int y2;
	int y3;

	int cy0;
	int cy1;
	int cy2;
	int cy3;

	double v0;
	double v1;
	double v2;
	double v3;
}
game_menu ;

typedef struct player {
	int 	score;
	int 	try;
	SDL_Surface	*face;
	SDL_Rect	pos;
} plyr;

typedef struct application {
	char 	**str;
	SDL_Window *win;
	SDL_Surface *srf;
	SDL_Surface *close;
	SDL_Surface *game_over;
	SDL_Surface *menu_btn;
	SDL_Surface *arrow_first;
	SDL_Surface *arrow_second;

	double game_over_v;
	double game_over_a;
	double game_over_time;
	int game_over_y;

	plyr	plr[NUMBER_OF_PLAYERS];
	int		cur_plr;
	//plyr	plr2;
	cards	*arr;
	int		OPN_CRDS_NBR;
	int		LEN_ARR;
	int		W;  //number of cols
	int		H;  // number of rows
	SDL_Surface *background;
	int		OFFSET_X;
	int 	OFFSET_Y;
	Mix_Music *backgroundSound;
	Mix_Chunk *correct;
	TTF_Font *font;
	bool	start_game;
	game_menu	menu;
	bool	game_finnished;
} 
app;

char *mx_strnew(const int size);
char *mx_strcat(char *s1, const char *s2);
int mx_strlen(const char *s);
char 	**mx_list_resourses(app *game);
void 	mx_set_start_val(app *game);
void	mx_app_loop(app *game);
void	mx_turn_over_card(app *game, int x, int y);
void 	window_cards_update(app *game);
void	players_score(app *game);
void	mx_open_all_cards(app *game);
void	mx_close_all_cards(app *game);
bool	is_choose_level(SDL_Surface *txt, int x, int y);
void	mx_start_game(app *game);
void	print_menu(app *game);

#endif
