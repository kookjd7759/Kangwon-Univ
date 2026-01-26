#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

void trim_right(char s[]) {
    int size = strlen(s);

    while (size > 0 && s[size - 1] == ' ') {
        s[size - 1] = '\0';
        size--;
    }
}

int main(void) { 
    char line[] = "This is a trim_right function.         ";

    trim_right(line);

    printf("%s\n", line);
}
