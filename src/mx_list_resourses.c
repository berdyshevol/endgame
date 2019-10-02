#include "header.h"

char **mx_list_resourses(app *game){

	(void)game;
	char **str = (char**)malloc(sizeof(char*)*CARDS_ARR_NUMBER);
	str[0] = "./res/animals/anim1.jpg";
	str[1] = "./res/animals/anim2.jpg";
	str[2] = "./res/animals/anim3.jpg";
	str[3] = "./res/animals/anim4.jpg";
	str[4] = "./res/animals/anim5.jpg";
	str[5] = "./res/animals/anim6.jpg";

	str[6] = "./res/disasters/dis1.jpg";
	str[7] = "./res/disasters/dis2.jpg";
	str[8] = "./res/disasters/dis3.jpg";
	str[9] = "./res/disasters/dis4.jpg";
	str[10] = "./res/disasters/dis5.jpg";
	str[11] = "./res/disasters/dis6.jpg";

	str[12] = "./res/food/food1.jpg";
	str[13] = "./res/food/food2.jpg";
	str[14] = "./res/food/food3.jpg";
	str[15] = "./res/food/food4.jpg";
	str[16] = "./res/food/food5.jpg";
	str[17] = "./res/food/food6.jpg";

	str[18] = "./res/light/light1.jpg";
	str[19] = "./res/light/light2.jpg";
	str[20] = "./res/light/light3.jpg";
	str[21] = "./res/light/light4.jpg";
	str[22] = "./res/light/light5.jpg";
	str[23] = "./res/light/light6.jpg";

	str[24] = "./res/music/mus1.jpg";
	str[25] = "./res/music/mus2.jpg";
	str[26] = "./res/music/mus3.jpg";
	str[27] = "./res/music/mus4.jpg";
	str[28] = "./res/music/mus5.jpg";
	str[29] = "./res/music/mus6.jpg";

	game->close = IMG_Load("./res/texture.jpg");
	if (game->close == NULL)
		mx_errorexit("SDL");
	
	game->background = IMG_Load("./res/background.jpg");
	if (game->background == NULL)
		mx_errorexit("SDL");
	game->background->clip_rect.x = 0;
	game->background->clip_rect.y = 0;

	game->start_game = false;
	SDL_Color text_clr =  {153, 45, 0, 0};
	game->menu.txt0 = TTF_RenderText_Solid(game->menu.font, "2 cards (4 x 6)", text_clr);
	game->menu.txt1 = TTF_RenderText_Solid(game->menu.font, "3 cards (3 x 6)", text_clr);
	game->menu.txt2 = TTF_RenderText_Solid(game->menu.font, "3 cards (5 x 6)", text_clr);
	game->menu.txt3 = TTF_RenderText_Solid(game->menu.font, "4 cards (4 x 4)", text_clr);

	SDL_Color text_clr_choose_level =  {0, 102, 0, 0};
	game->menu.choose_level = TTF_RenderText_Solid(game->menu.choose_level_font, "Choose level", text_clr_choose_level);
	

	game->game_over = IMG_Load("res/game_over.jpg");
	if (game->game_over == NULL)
		mx_errorexit("SDL");
	
	// Mix_Music *backgroundSound = NULL;
    //     backgroundSound = Mix_LoadMUS("res/music.mp3");

	return (str);


}

