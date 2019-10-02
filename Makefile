NAME = endgame
CC = clang
#CFLAG = -std=c11 -Wall -Wextra -Werror -Wpedantic
CFLAG = -std=c11 -Wall -Wextra -Werror -Wpedantic -ggdb3 -O0 -lm
SDL2 = -I ./Frameworks/SDL2.framework/Versions/A/Header -F ./Frameworks -framework SDL2
SDL2_IMAGE = -I ./Frameworks/SDL2_image.framework/Versions/A/Header -F ./Frameworks/ -framework SDL2_image
SDL2_TTF = -I ./Frameworks/SDL2_ttf.framework/Versions/A/Headers -F ./Frameworks/ -framework SDL2_ttf
SDL2_MIXER = -I ./Frameworks/SDL2_mixer.framework/Versions/A/Headers -F ./Frameworks/ -framework SDL2_mixer
SRC = src/main.c src/mx_app_loop.c src/mx_choose_level_game.c src/mx_errorexit.c src/mx_list_resourses.c src/mx_player_score.c src/mx_set_start_val.c src/mx_strcat.c src/mx_strlen.c src/mx_strnew.c src/mx_turn_over_card.c src/print_screen.c 
SRCS = main.c mx_app_loop.c mx_choose_level_game.c mx_errorexit.c mx_list_resourses.c mx_player_score.c mx_set_start_val.c mx_strcat.c mx_strlen.c mx_strnew.c mx_turn_over_card.c print_screen.c
HDR = header.h
INC = inc/header.h

all: install clean
install:
	@cp $(SRC) .
	@cp $(INC) .
	@$(CC) $(CFLAG) $(SRCS) -o $(NAME) -I $(HDR) $(SDL2) $(SDL2_IMAGE) $(SDL2_TTF) $(SDL2_MIXER) -rpath ./frameworks
uninstall:
	@rm -rf $(SRCS)
	@rm -rf $(HDR)
	@rm -rf $(NAME)
	@rm -rf endgame.dSYM
clean:
	@rm -rf $(SRCS)
	@rm -rf $(HDR)
reinstall: uninstall all
