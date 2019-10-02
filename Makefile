CC = clang
#CFLAG = -std=c11 -Wall -Wextra -Werror -Wpedantic
CFLAG = -std=c11 -Wall -Wextra -Werror -Wpedantic -ggdb3 -O0 -lm
SDL2 = -I ./Frameworks/SDL2.framework/Versions/A/Header -F ./Frameworks -framework SDL2
SDL2_IMAGE = -I ./Frameworks/SDL2_image.framework/Versions/A/Header -F ./Frameworks/ -framework SDL2_image
SDL2_TTF = -I ./Frameworks/SDL2_ttf.framework/Versions/A/Headers -F ./Frameworks/ -framework SDL2_ttf
NAME = endgame
PATHS = src/main.c src/mx_app_loop.c src/mx_choose_level_game.c src/mx_erroexit.c 
PATH = main.c mx_app_loop.c

all: install clean
install:
	cp src/*.c inc/*.h .
	#cp PATHS .
	cp inc/header.h .
	${CC} ${CFLAG} *.c -o ${NAME} ${SDL2} ${SDL2_IMAGE} ${SDL2_TTF} -rpath ./frameworks
uninstall:
	rm -rf ${NAME}
clean:
	#rm -rf *.c
	#rm -rf *.h
	#rm -rf *.o
reinstall: uninstall all
