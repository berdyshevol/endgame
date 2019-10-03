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

void do_anim(double *t, int *y, double *v, int ymax) {
	double dt = 0.01;;
	*t = *t + dt;
	SDL_Delay(1000 * dt);
	*y = *y + (*v) * dt + 2000 * dt * (*t);
	
	if (*y > ymax){
		*v = -1500;// -1 * (game->game_over_a * game->game_over_time);
		*y = ymax;
		
		
	}	

	//printf("y=%d v=%f t=%f\n", game->game_over_y, game->game_over
}

void make_anim(app *game) {
	if (!game->menu.anim) return;
	if (game->menu.t0 < 1.7) {
		do_anim(&(game->menu.t0), &(game->menu.cy0), &(game->menu.v0), game->menu.y0);
	}
	else if (game->menu.t1 < 1.7) {
		do_anim(&(game->menu.t1), &(game->menu.cy1), &(game->menu.v1), game->menu.y1);
	}
	else if (game->menu.t2 < 1.7) {
		do_anim(&(game->menu.t2), &(game->menu.cy2), &(game->menu.v2), game->menu.y2);
	}
	else if (game->menu.t3 < 1.7) {
		do_anim(&(game->menu.t3), &(game->menu.cy3), &(game->menu.v3), game->menu.y3);
	}
	else
		game->menu.anim = false;
}

void print_menu(app *game) {
	make_anim(game);

	SDL_memset(game->srf->pixels, 0, game->srf->h * game->srf->pitch);
	SDL_BlitSurface(game->background, NULL, game->srf, &(game->background->clip_rect));

	game->menu.choose_level->clip_rect.y = WINDOW_HEIGHT/2 -500;
	game->menu.choose_level->clip_rect.x = (WINDOW_WIDTH / 2) - (game->menu.choose_level->clip_rect.w / 2);
	SDL_BlitSurface(game->menu.choose_level, NULL, game->srf, &(game->menu.choose_level->clip_rect));

	game->menu.txt0->clip_rect.y = game->menu.cy0;
	game->menu.txt0->clip_rect.x = (WINDOW_WIDTH / 2) - (game->menu.txt0->clip_rect.w / 2);
	SDL_BlitSurface(game->menu.txt0, NULL, game->srf, &(game->menu.txt0->clip_rect));

	game->menu.txt1->clip_rect.y = game->menu.cy1;
	game->menu.txt1->clip_rect.x = (WINDOW_WIDTH / 2) - (game->menu.txt1->clip_rect.w / 2);
	SDL_BlitSurface(game->menu.txt1, NULL, game->srf, &(game->menu.txt1->clip_rect));

	game->menu.txt2->clip_rect.x = (WINDOW_WIDTH / 2) - (game->menu.txt2->clip_rect.w / 2);
	game->menu.txt2->clip_rect.y = game->menu.cy2;
	SDL_BlitSurface(game->menu.txt2, NULL, game->srf, &(game->menu.txt2->clip_rect));

	game->menu.txt3->clip_rect.y = game->menu.cy3;
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
		game->game_over_y += game->game_over_v * dt + game->game_over_a * dt * game->game_over_time;
		
		if (game->game_over_y > WINDOW_HEIGHT - 700){
			game->game_over_v =-2000;// -1 * (game->game_over_a * game->game_over_time);
			
			game->game_over_y = WINDOW_HEIGHT - 700;
		}	
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

