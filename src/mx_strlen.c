int mx_strlen(const char *s) {
    if (!s) {
        return 0;
    }
    int l = 0;
    while (*s != '\0') {
        l++;
        s++;
    }
    return l;
}

