#include "header.h"

char *mx_strcat(char *s1, const char *s2) {
    int i = mx_strlen(s1);
    int j = 0;
    if (s2)
        while ((s1[i] = s2[j]) != '\0') {
            i++;
            j++;
        }
    return s1;
}

