#include "header.h"

void mx_start_game(app *game) {
	game->start_game = true;
	mx_set_start_val(game);
	//---------------make open all cards before start to play
	// mx_open_all_cards(game);
	// window_cards_update(game);
	// SDL_Delay(SECONDS_OPEN);
	mx_close_all_cards(game);
	window_cards_update(game);
	SDL_Delay(500);
	//----------------------------
}

bool is_choose_level(SDL_Surface *txt, int x, int y) {
	int x_min = txt->clip_rect.x;
	int x_max = x_min + txt->clip_rect.w;
	int y_min = txt->clip_rect.y;
	int y_max = y_min + txt->clip_rect.h;
	if (x >= x_min && x <= x_max) {
		if (y >= y_min && y <= y_max) {
			return true;
		}
	}
	return false;
}

