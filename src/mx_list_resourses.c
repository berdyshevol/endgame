#include "header.h"

char **mx_list_resourses(app *game){

	(void)game;
	char **str = (char**)malloc(sizeof(char*)*CARDS_ARR_NUMBER);
	str[0] = "./res/pictures/animals/anim1.jpg";
	str[1] = "./res/pictures/animals/anim2.jpg";
	str[2] = "./res/pictures/animals/anim3.jpg";
	str[3] = "./res/pictures/animals/anim4.jpg";
	str[4] = "./res/pictures/animals/anim5.jpg";
	str[5] = "./res/pictures/animals/anim6.jpg";

	str[6] = "./res/pictures/disasters/dis1.jpg";
	str[7] = "./res/pictures/disasters/dis2.jpg";
	str[8] = "./res/pictures/disasters/dis3.jpg";
	str[9] = "./res/pictures/disasters/dis4.jpg";
	str[10] = "./res/pictures/disasters/dis5.jpg";
	str[11] = "./res/pictures/disasters/dis6.jpg";

	str[12] = "./res/pictures/food/food1.jpg";
	str[13] = "./res/pictures/food/food2.jpg";
	str[14] = "./res/pictures/food/food3.jpg";
	str[15] = "./res/pictures/food/food4.jpg";
	str[16] = "./res/pictures/food/food5.jpg";
	str[17] = "./res/pictures/food/food6.jpg";

	str[18] = "./res/pictures/light/light1.jpg";
	str[19] = "./res/pictures/light/light2.jpg";
	str[20] = "./res/pictures/light/light3.jpg";
	str[21] = "./res/pictures/light/light4.jpg";
	str[22] = "./res/pictures/light/light5.jpg";
	str[23] = "./res/pictures/light/light6.jpg";

	str[24] = "./res/pictures/music/mus1.jpg";
	str[25] = "./res/pictures/music/mus2.jpg";
	str[26] = "./res/pictures/music/mus3.jpg";
	str[27] = "./res/pictures/music/mus4.jpg";
	str[28] = "./res/pictures/music/mus5.jpg";
	str[29] = "./res/pictures/music/mus6.jpg";

	game->close = IMG_Load("./res/pictures/texture.jpg");
	if (game->close == NULL)
		mx_errorexit("SDL");
	
	game->background = IMG_Load("./res/pictures/background.jpg");
	if (game->background == NULL)
		mx_errorexit("SDL");
	game->background->clip_rect.x = 0;
	game->background->clip_rect.y = 0;

	game->menu_btn = IMG_Load("./res/pictures/plus.jpg");
	if (game->menu_btn == NULL)
		mx_errorexit("SDL");
	game->menu_btn->clip_rect.x = 30;
	game->menu_btn->clip_rect.y = 30;

	game->start_game = false;

	game->font = TTF_OpenFont("./res/fonts/tahoma/TAHOMAB0.TTF", 30);
	if (!game->font)
		mx_errorexit("SDL");

	game->menu.font = TTF_OpenFont("./res/fonts/tahoma/TAHOMAB0.TTF", 80);
	if (!game->menu.font)
		mx_errorexit("SDL");

	game->menu.choose_level_font = TTF_OpenFont("./res/fonts/tahoma/TAHOMAB0.TTF", 120);
	if (!game->menu.choose_level_font)
		mx_errorexit("SDL");
	
	SDL_Color text_clr =  {153, 45, 0, 0};
	game->menu.txt0 = TTF_RenderText_Solid(game->menu.font, "2 cards (4 x 6)", text_clr);
	game->menu.txt1 = TTF_RenderText_Solid(game->menu.font, "3 cards (3 x 6)", text_clr);
	game->menu.txt2 = TTF_RenderText_Solid(game->menu.font, "3 cards (5 x 6)", text_clr);
	game->menu.txt3 = TTF_RenderText_Solid(game->menu.font, "4 cards (4 x 4)", text_clr);

	SDL_Color text_clr_choose_level =  {0, 102, 0, 0};
	game->menu.choose_level = TTF_RenderText_Solid(game->menu.choose_level_font, "Choose level", text_clr_choose_level);
	

	game->game_over = IMG_Load("res/pictures/game_over.jpg");
	if (game->game_over == NULL)
		mx_errorexit("SDL");
	
	game->backgroundSound = Mix_LoadMUS("res/music/music.mp3");
	if (game->backgroundSound == NULL)
		mx_errorexit("SDL");
	Mix_VolumeMusic(MIX_MAX_VOLUME/30);
	Mix_PlayMusic(game->backgroundSound, -1);

	game->correct = Mix_LoadWAV("res/music/correct.mp3");
	if (game->correct == NULL)
		mx_errorexit("SDL");
	Mix_VolumeChunk(game->correct, MIX_MAX_VOLUME/10);

	return (str);


}

