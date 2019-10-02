#include "header.h"

char *itoa(int i, char b[]) {
    char const digit[] = "0123456789";
    char *p = b;
    if (i < 0) {
        *p++ = '-';
        i *= -1;
    }
    int shifter = i;
    ++p;
    shifter = shifter / 10;
    while (shifter) {
        ++p;
        shifter = shifter / 10;
    }
    *p = '\0';
    *--p = digit[i % 10];
    i = i / 10;
    while (i) {
        *--p = digit[i % 10];
        i = i / 10;
    }
    return b;
}

void players_score(app *game) {
    int max_w;
	int max_h;
	SDL_GetWindowSize(game->win, &max_w, &max_h);

    SDL_Color textColON = {102, 17, 0, 0};
    SDL_Color textColOFF =  {204, 102, 0, 0};
    SDL_Color textCol0 = textColOFF;
    SDL_Color textCol1 = textColOFF;

    //for (int i = 0; i < NUMBER_OF_PLAYERS; i++) {
    if (!game->game_finnished) {
        if (game->cur_plr == 0) {
            textCol0 = textColON;
        }
        else {
            textCol1 = textColON;
        }
    }
    // location of arrow
    game->arrow_first->clip_rect.x = max_w / 2 - 40;
    game->arrow_first->clip_rect.y = 20;
    game->arrow_second->clip_rect.x = max_w / 2 - 40;
    game->arrow_second->clip_rect.y = 20;

    // First player's score
    char text0[100] = "First player's score: ";
    char *score0 = mx_strnew(5);
    itoa(game->plr[0].score, score0);
    mx_strcat(text0, score0);
    game->plr[0].face = TTF_RenderText_Solid(game->font, text0, textCol0);
    game->plr[0].face->clip_rect.x = max_w / 2 - 550;
    game->plr[0].face->clip_rect.y = 30;
    //}
    // Second player's score
    char text1[100] = "Second player's score: ";
    char *score1 = mx_strnew(5);
    itoa(game->plr[1].score, score1);
    mx_strcat(text1, score1);
    game->plr[1].face = TTF_RenderText_Solid(game->font, text1, textCol1);
    game->plr[1].face->clip_rect.x = max_w / 2 + 100;
    game->plr[1].face->clip_rect.y = 30;

    free(score0);
    free(score1);
}
