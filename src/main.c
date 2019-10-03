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

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) != 0)
	  	mx_errorexit("SDL");
	
	if(TTF_Init() == -1)
		mx_errorexit("SDL");
	
	//-------------------------turn or init for randomaizer
	time_t t;
	srand( time(&t));
	//-------------------------------------
}

void anim_menu(app *game) {
	SDL_memset(game->srf->pixels, 0, game->srf->h * game->srf->pitch);
	SDL_BlitSurface(game->background, NULL, game->srf, &(game->background->clip_rect));

	game->menu.choose_level->clip_rect.y = WINDOW_HEIGHT/2 -500;
	game->menu.choose_level->clip_rect.x = (WINDOW_WIDTH / 2) - (game->menu.choose_level->clip_rect.w / 2);
	SDL_BlitSurface(game->menu.choose_level, NULL, game->srf, &(game->menu.choose_level->clip_rect));

	if (game->menu.on_txt0) {
		game->menu.txt0->clip_rect.y = WINDOW_HEIGHT/2 -300;
		game->menu.txt0->clip_rect.x = (WINDOW_WIDTH / 2) - (game->menu.txt0->clip_rect.w / 2);
		SDL_BlitSurface(game->menu.txt0, NULL, game->srf, &(game->menu.txt0->clip_rect));
	}
	if (game->menu.on_txt1) {
		game->menu.txt1->clip_rect.y = WINDOW_HEIGHT/2 - 150;
		game->menu.txt1->clip_rect.x = (WINDOW_WIDTH / 2) - (game->menu.txt1->clip_rect.w / 2);
		SDL_BlitSurface(game->menu.txt1, NULL, game->srf, &(game->menu.txt1->clip_rect));
	}
	if (game->menu.on_txt2) {
		game->menu.txt2->clip_rect.x = (WINDOW_WIDTH / 2) - (game->menu.txt2->clip_rect.w / 2);
		game->menu.txt2->clip_rect.y = WINDOW_HEIGHT/2 + 0;
		SDL_BlitSurface(game->menu.txt2, NULL, game->srf, &(game->menu.txt2->clip_rect));
	}
	if (game->menu.on_txt3) {
		game->menu.txt3->clip_rect.y = WINDOW_HEIGHT/2 + 150;
		game->menu.txt3->clip_rect.x = (WINDOW_WIDTH / 2) - (game->menu.txt3->clip_rect.w / 2);
		SDL_BlitSurface(game->menu.txt3, NULL, game->srf, &(game->menu.txt3->clip_rect));
	}
	SDL_Delay(5000);
	SDL_UpdateWindowSurface(game->win);
}

void init_settings(app *game) {
	game->menu.cy0 = -100;
	game->menu.cy1 = -100;
	game->menu.cy2 = -100;
	game->menu.cy3 = -100;
	game->menu.v0 = 1000;
	game->menu.v1 = 1000;
	game->menu.v2 = 1000;
	game->menu.v3 = 1000;
	game->menu.t0 = 0;
	game->menu.t1 = 0;
	game->menu.t2 = 0;
	game->menu.t3 = 0;
	game->menu.y0 = WINDOW_HEIGHT/2 -300;
	game->menu.y1 = WINDOW_HEIGHT/2 - 150;
	game->menu.y2 = WINDOW_HEIGHT/2 + 0;
	game->menu.y3 = WINDOW_HEIGHT/2 + 150;
	game->menu.anim = true;
}

int main() {
	app *game = (app*)malloc(sizeof(app));
	init_settings(game);
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

