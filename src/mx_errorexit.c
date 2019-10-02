#include "header.h"

void mx_errorexit(char *str) {
	int err = errno;
	if (str == NULL)
		mx_printerror(strerror(err));
	else
		mx_printerror((char*)SDL_GetError());
	exit(err);
}

void mx_printerror(char *str) {
	for (int i = 0; str[i] != '\0'; i++)
		write(2, &str[i], 1);
	write(2, "\n", 1);
}

