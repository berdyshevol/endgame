#include "header.h"

int	mx_how_much_open(app *game){
	int count = 0;
	for (int i = 0; i < game->LEN_ARR; i++){
		if (game->arr[i].open == true && game->arr[i].print == true)
			count++;
	}
	return (count);
}

void	mx_click_card(app *game, int x, int y){
	for (int i = 0; i < game->LEN_ARR; i++){
		int x_min = game->arr[i].pos.x;
		int x_max = game->arr[i].pos.x + game->arr[i].pos.w;
		int y_min = game->arr[i].pos.y;
		int y_max = game->arr[i].pos.y + game->arr[i].pos.h;
		if (x >= x_min && x <= x_max){
			if (y >= y_min && y <= y_max){
				game->arr[i].open = true;

			}
		}
	}
}

bool	mx_is_same_ctgr(app *game){
	int type_a = 0;
	for (int i = 0; i < game->LEN_ARR; i++){
		if (game->arr[i].open == true) {
			if (type_a == 0) {
				type_a = game->arr[i].type;
			}
			else {
				if (game->arr[i].type != type_a)
					return false;
			}
		}
	}
	return true;
}

void	mx_close_all_cards(app *game)
{
	for (int i = 0; i < game->LEN_ARR; i++) {
		game->arr[i].open = false;
	}
}

void	mx_open_all_cards(app *game)
{
	for (int i = 0; i < game->LEN_ARR; i++) {
		game->arr[i].open = true;
	}
}

void	mx_remove_open_cards(app *game)
{
	for (int i = 0; i < game->LEN_ARR; i++) {
		if (game->arr[i].open == true){
			game->arr[i].print = false;
		}
//		arr[i].open = false;
	}
}

void next_player(app *game) {
	(game->cur_plr)++;
	if (game->cur_plr == NUMBER_OF_PLAYERS)
		game->cur_plr = 0;
}

void	mx_turn_over_card(app *game, int x, int y) {
	mx_click_card(game, x, y);
	window_cards_update(game);
	if (mx_how_much_open(game) == game->OPN_CRDS_NBR){
		if (mx_is_same_ctgr(game)){//if true => score if faulse => change player && try--; //
			//mx_add_score(app *game);
			mx_remove_open_cards(game);
			mx_close_all_cards(game);
			(game->plr[game->cur_plr].score)++;
			next_player(game);
			SDL_Delay(500);

		}
		else{
			//printf("wrong type\n");
			
			mx_close_all_cards(game);
			//printf("try-- if (try == 0) change player \n\n");
			next_player(game);
			SDL_Delay(500);
		}
	}
	//window_cards_update(game);
	//players_score(game);
}

