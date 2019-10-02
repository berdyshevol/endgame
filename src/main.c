#include "header.h"

void mx_init_sdl(app *game) {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		mx_errorexit("SDL");
	game->win = SDL_CreateWindow("card game",
								 SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
								 WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
	if (game->win == NULL)
		mx_errorexit("SDL");
	game->srf = SDL_GetWindowSurface(game->win);
	if (game->srf == NULL)
		mx_errorexit("SDL");

    // if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) != 0)
	//  	mx_errorexit("SDL");
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	
	if(TTF_Init() == -1)
		mx_errorexit("SDL");
	
	//-------------------------turn or init for randomaizer
	time_t t;
	srand( time(&t));
	//-------------------------------------
}

int main() {
	app *game = (app*)malloc(sizeof(app));

	mx_init_sdl(game);
	game->str = mx_list_resourses(game);

	mx_app_loop(game);
//	system("leaks -q endgame");
	SDL_DestroyWindow(game->win);
	Mix_FreeMusic(game->backgroundSound);
	Mix_CloseAudio();
	SDL_Quit();
	return 0;
}

