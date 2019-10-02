#include "header.h"

bool	mx_is_game_over(app *game){
	int count_non_print_cards = 0;
	for (int i = 0; i < game->LEN_ARR; i++){
		if(game->arr[i].print == false)
			count_non_print_cards++;
	}
	if (count_non_print_cards == game->LEN_ARR)
		return true;
	return false;
}

void print_menu(app *game) {
	SDL_memset(game->srf->pixels, 0, game->srf->h * game->srf->pitch);
	SDL_BlitSurface(game->background, NULL, game->srf, &(game->background->clip_rect));

	game->menu.choose_level->clip_rect.y = WINDOW_HEIGHT/2 -500;
	game->menu.choose_level->clip_rect.x = (WINDOW_WIDTH / 2) - (game->menu.choose_level->clip_rect.w / 2);
	SDL_BlitSurface(game->menu.choose_level, NULL, game->srf, &(game->menu.choose_level->clip_rect));

	game->menu.txt0->clip_rect.y = WINDOW_HEIGHT/2 -300;
	game->menu.txt0->clip_rect.x = (WINDOW_WIDTH / 2) - (game->menu.txt0->clip_rect.w / 2);
	SDL_BlitSurface(game->menu.txt0, NULL, game->srf, &(game->menu.txt0->clip_rect));

	game->menu.txt1->clip_rect.y = WINDOW_HEIGHT/2 - 150;
	game->menu.txt1->clip_rect.x = (WINDOW_WIDTH / 2) - (game->menu.txt1->clip_rect.w / 2);
	SDL_BlitSurface(game->menu.txt1, NULL, game->srf, &(game->menu.txt1->clip_rect));

	game->menu.txt2->clip_rect.x = (WINDOW_WIDTH / 2) - (game->menu.txt2->clip_rect.w / 2);
	game->menu.txt2->clip_rect.y = WINDOW_HEIGHT/2 + 0;
	SDL_BlitSurface(game->menu.txt2, NULL, game->srf, &(game->menu.txt2->clip_rect));

	game->menu.txt3->clip_rect.y = WINDOW_HEIGHT/2 + 150;
	game->menu.txt3->clip_rect.x = (WINDOW_WIDTH / 2) - (game->menu.txt3->clip_rect.w / 2);
	SDL_BlitSurface(game->menu.txt3, NULL, game->srf, &(game->menu.txt3->clip_rect));

	SDL_UpdateWindowSurface(game->win);
}

void window_cards_update(app *game) {
	SDL_memset(game->srf->pixels, 0, game->srf->h * game->srf->pitch);

	SDL_BlitSurface(game->background, NULL, game->srf, &(game->background->clip_rect));

	for (int i = 0; i < game->LEN_ARR; i++){
		if (game->arr[i].print == true){
			if (game->arr[i].open == true)
				SDL_BlitSurface(game->arr[i].face, NULL, game->srf, &game->arr[i].pos);
			else if (game->arr[i].open == false)
				SDL_BlitSurface(game->close, NULL, game->srf, &game->arr[i].pos);
		}
	}

	if(mx_is_game_over(game) == true) {
		game->game_finnished = true;
		SDL_BlitSurface(game->game_over, NULL, game->srf, &(game->game_over->clip_rect));
	}

	SDL_BlitSurface(game->menu_btn, NULL, game->srf, &(game->menu_btn->clip_rect));

	SDL_BlitSurface(game->plr[0].face, NULL, game->srf, &(game->plr[0].face->clip_rect));
	SDL_BlitSurface(game->plr[1].face, NULL, game->srf, &(game->plr[1].face->clip_rect));

	if (!game->game_finnished) {
		if (game->cur_plr == 0) {
			SDL_BlitSurface(game->arrow_first, NULL, game->srf, &(game->arrow_first->clip_rect));
		}
		else {
			SDL_BlitSurface(game->arrow_second, NULL, game->srf, &(game->arrow_second->clip_rect));
		}
	}

	SDL_UpdateWindowSurface(game->win);
}

