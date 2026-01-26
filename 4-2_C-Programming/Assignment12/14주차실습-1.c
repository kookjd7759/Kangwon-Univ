#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
    printf("파일 이름을 입력하시오: ");
    char name[100]; gets_s(name, 100);

    FILE* fp = fopen(name, "r");
    if (fp == NULL) {
        printf("ERROR::Can't open the file.\n");
        return -1;
    }

    int c, line = 0;
    printf("%d\t", line++);
    while ((c = fgetc(fp)) != EOF) {
        putchar(c);

        if (c == '\n') {
            printf("%d\t", line++);
        }
    }

    fclose(fp);

    return 0;
}
