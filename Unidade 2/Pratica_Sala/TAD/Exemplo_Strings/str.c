int comprimento(char* str) {
    int len = 0;
    while (*str != '\0') {
        len++;
        str++;
    }
    return len;
}

void copia(char* dest, char* orig) {
    while (*orig != '\0') {
        *dest = *orig;
        dest++;
        orig++;
    }
    *dest = '\0';
}

void concatena(char* dest, char* orig) {
    while (*dest != '\0') {
        dest++;
    }
    while (*orig != '\0') {
        *dest = *orig;
        dest++;
        orig++;
    }
    *dest = '\0';
}
