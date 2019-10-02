NAME = endgame

SRC = src/main.c \
	src/mx_app_loop.c \
	src/mx_choose_level_game.c \
	src/mx_errorexit.c \
	src/mx_list_resourses.c \
	src/mx_player_score.c \
	src/mx_set_start_val.c \
	src/mx_strcat.c \
	src/mx_strlen.c \
	src/mx_strnew.c \
	src/mx_turn_over_card.c \
	src/print_screen.c

INC = inc/header.h

CFILES = main.c \
    mx_app_loop.c \
	mx_choose_level_game.c \
	mx_errorexit.c \
	mx_list_resourses.c \
	mx_player_score.c \
	mx_set_start_val.c\
	mx_strcat.c \
	mx_strlen.c \
	mx_strnew.c \
	mx_turn_over_card.c \
	print_screen.c

HFILES = header.h

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic
DFLAGS = -fsanitize=address -g
RFLAGS = -Ofast

FFLAGS = -I ./inc/Frameworks/SDL2.framework/Versions/A/Headers \
		-F ./inc/Frameworks -framework SDL2 -rpath ./inc/Frameworks \
		-I ./inc/Frameworks/SDL2_image.framework/Versions/A/Headers \
		-F ./inc/Frameworks -framework SDL2_image -rpath ./inc/Frameworks \
		-I ./inc/Frameworks/SDL2_mixer.framework/Versions/A/Headers \
		-F ./inc/Frameworks -framework SDL2_mixer -rpath ./inc/Frameworks \
		-I ./inc/Frameworks/SDL2_ttf.framework/Versions/A/Headers \
		-F ./inc/Frameworks -framework SDL2_ttf -rpath ./inc/Frameworks

all: install clean
dbg: debug clean
release: build clean

install:
		@cp $(SRC) .
		@cp $(INC) .
		@clang $(CFLAGS) $(FFLAGS) -o $(NAME) $(CFILES)
debug:
		@cp $(SRC) .
		@cp $(INC) .
		@clang $(CFLAGS) $(FFLAGS) $(DFLAGS) -o $(NAME) $(CFILES)
build:
		@cp $(SRC) .
		@cp $(INC) .
		@clang $(CFLAGS) $(FFLAGS) $(RFLAGS) -o $(NAME) $(CFILES)
clean:
		@rm -rf $(CFILES)
		@rm -rf $(HFILES)
		@rm -rf endgame.dSYM
uninstall: clean
		@rm -rf $(NAME)
reinstall: uninstall all
