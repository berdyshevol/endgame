#include "header.h"

int randomaizer(int min, int max) {
	int delta = max - min;
	int res = (int)((rand() / (float)(RAND_MAX)) * delta) + min;
	return res;
}

bool need_change(cards *arr, int len) {
	for (int i = 0; i < len; i++) {
		if (arr[i].id != -1)
			return true;
	}
	return false;
}

void mx_set_random(cards *arr, int len) {
	while(need_change(arr, len) == true)
	{
		int a = randomaizer(0, 29);
		int b = randomaizer(0, 29);
		if (a != b) {
			cards buf = arr[a];
			arr[a] = arr[b];
			arr[b] = buf;
			arr[a].id = -1;
			arr[b].id = -1;
		}
	}
}

void mx_set_greed(app *game, int len) {
	game->arr = (cards*)malloc(sizeof(cards) * len);
	for(int i = 0; i < len; i++) {
		game->arr[i].id = i;
		game->arr[i].face = IMG_Load(game->str[i]);
		if (game->arr[i].face == NULL)
			mx_errorexit("SDL");
		game->arr[i].type = (i / 6) + 1;
		game->arr[i].print = true;
		game->arr[i].open = false;
		game->arr[i].pos = game->arr[i].face->clip_rect;
	}
}

void mx_set_coordinate(cards *arr, int w, int h) {
	for (int i = 0; i < h; i++){
		for (int j = 0; j < w; j++){
			arr[i*w + j].pos.x = ((200+20)*j)  + 20;
			arr[i*w + j].pos.y = ((200+20)*i)  + 20;
		}
	}
}

void mx_download_pics(app *game, int *temp_arr) {
	game->arr = (cards*)malloc(sizeof(cards) * game->LEN_ARR);
	for(int i = 0; i < game->LEN_ARR; i++) {
		game->arr[i].id = i;
		game->arr[i].face = IMG_Load(game->str[temp_arr[i]]);
		if (game->arr[i].face == NULL)
			mx_errorexit("SDL");
		game->arr[i].type = (temp_arr[i] / 6) + 1;
		game->arr[i].print = true;
		game->arr[i].open = false;
		game->arr[i].pos = game->arr[i].face->clip_rect;
	}
}

void mx_fill_coordinates(app *game) {
	int max_w;
	int max_h;
	SDL_GetWindowSize(game->win, &max_w, &max_h);
	int w = game->W;
	int h = game->H;
	game->OFFSET_X = (max_w - (200 + 20) * w) / 2;
	game->OFFSET_Y = (max_h - (200 + 20) * h) / 2 + 30;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			game->arr[i*w + j].pos.x = ((200+20)*j)  + 20 + game->OFFSET_X;
			game->arr[i*w + j].pos.y = ((200+20)*i)  + 20 + game->OFFSET_Y;
		}

	}
}

bool is_in_arr(int *arr, int size, int new_item) {
	for(int i = 0; i < size; i++) 
		if (arr[i] == new_item)
			return true;
	return false;
}

void mx_fill_arr(app *game) {
	game->LEN_ARR = game->W * game->H;
	//создать временный массив из каждого по 3
	int *temp_arr = malloc(sizeof(int) * game->LEN_ARR);
	if (!temp_arr) mx_errorexit("not enough memory\n");
	for(int i = 0; i < game->LEN_ARR; i++)
		temp_arr[i] = -1;
	int category = 0;
	int count = 0;
	while(count < game->LEN_ARR) {
		for(int j = 0; j < game->OPN_CRDS_NBR; j++) {
			int new_item = category * 6 + randomaizer(0, 6);
			while(is_in_arr(temp_arr, game->LEN_ARR, new_item))
				new_item = category * 6 + randomaizer(0, 6);
			temp_arr[count] = new_item;
			count++;
		}
		category++;
		if (category > CARDS_ARR_NUMBER / 6 - 1)
			category = 0;
	}

	// перемешать
	for(int i = 0; i < game->LEN_ARR; i++) {
		int i = randomaizer(0, game->LEN_ARR);
		int j = randomaizer(0, game->LEN_ARR);
		//swap i and j
		int t = temp_arr[i];
		temp_arr[i] = temp_arr[j];
		temp_arr[j] = t;
	}
	// заскачать фото
	mx_download_pics(game, temp_arr);
	// заполнить координаты
	mx_fill_coordinates(game);
	free(temp_arr);
 }

void mx_set_start_val(app *game) {
	game->plr[0].score = 0;
	game->plr[1].score = 0;
	game->cur_plr = 0;
	game->game_finnished = false;
	players_score(game);
	int max_w;
	int max_h;
	SDL_GetWindowSize(game->win, &max_w, &max_h);
	game->game_over->clip_rect.x = WINDOW_WIDTH / 2 - 234;//max_w / - 234;
	game->game_over_y = GAME_OVER_H;
	game->game_over_v = 1000;
	game->game_over_a = 2000;
	game->game_over_time = 0;

	

	mx_fill_arr(game);
}

