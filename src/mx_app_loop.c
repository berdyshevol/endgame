#include "header.h"

void mx_app_loop(app *game){
	SDL_Event event;
	bool on = true;
	int x;
	int y;
	bool click = false;

	while (on == true) {
		while (SDL_PollEvent(&event)) {
			x = event.button.x;
			y = event.button.y;
			if (event.type == SDL_QUIT)
				on = false;
			if (event.type == SDL_MOUSEBUTTONUP || event.type == SDL_MOUSEBUTTONDOWN)
				click = (event.type == SDL_MOUSEBUTTONUP) ? false : true;

		}
		if (game->start_game == true){
			if (click == true)
				mx_turn_over_card(game, x, y);

			players_score(game);
			window_cards_update(game);
		}
		else{
			print_menu(game);
			if (click == true) {
				if(is_choose_level(game->menu.txt0, x, y)){
					game->OPN_CRDS_NBR = 2;
					game->H = 4;
					game->W = 6;
					mx_start_game(game);
				}
				if(is_choose_level(game->menu.txt1, x, y)){
					game->OPN_CRDS_NBR = 3;
					game->H = 3;
					game->W = 5;
					mx_start_game(game);
				}
				if(is_choose_level(game->menu.txt2, x, y)){
					game->OPN_CRDS_NBR = 3;
					game->H = 5;
					game->W = 6;
					mx_start_game(game);
				}
				if(is_choose_level(game->menu.txt3, x, y)){
					game->OPN_CRDS_NBR = 4;
					game->H = 4;
					game->W = 4;
					mx_start_game(game);
				}
				
			}
		}
	}
}

