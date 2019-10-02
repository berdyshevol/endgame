#include "header.h"

bool mx_is_game_over(app *game) {
	int count_non_print_cards = 0;
	for(int i = 0; i < game->LEN_ARR; i++) {
		if (game->arr[i].print == false)
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

	if(mx_is_game_over(game) == true) {
	// if (true)	{
		double dt = 0.01;
		game->game_finnished = true;
		game->game_over_time += dt;
		SDL_Delay(1000 * dt);
		//game->game_over_y += game->game_over_v * dt;
		game->game_over_y += game->game_over_v * dt + game->game_over_a * dt * game->game_over_time;
		//dy = game->game_over_a / 2 * game->game_over_time * game->game_over_time + game->game_over_v * game->game_over_time;
		//y = game->game_over_v * game->game_over_time + 100;
		
		if (game->game_over_y > WINDOW_HEIGHT - 700){
			game->game_over_v =-1000;// -1 * (game->game_over_a * game->game_over_time);
			
			game->game_over_y = WINDOW_HEIGHT - 700;
			//printf("%f %d", game->game_over_v, game->game_over_y);
			//exit(0);
			//game->game_over_v = -game->game_over_v;
		}	
		// if (game->game_over_y < GAME_OVER_H) {
		// 	game->game_over_v = -game->game_over_v;
		// 	game->game_over_y = GAME_OVER_H;
		// }

		printf("y=%d v=%f t=%f\n", game->game_over_y, game->game_over_v, game->game_over_time);
		game->game_over->clip_rect.y = game->game_over_y;
		SDL_BlitSurface(game->game_over, NULL, game->srf, &(game->game_over->clip_rect));
	}
	else {
		for(int i = 0; i < game->LEN_ARR; i++){
			if (game->arr[i].print == true){
				if (game->arr[i].open == true)
					SDL_BlitSurface(game->arr[i].face, NULL, game->srf, &game->arr[i].pos);
				else if (game->arr[i].open == false)
					SDL_BlitSurface(game->close, NULL, game->srf, &game->arr[i].pos);
			}
		}
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

