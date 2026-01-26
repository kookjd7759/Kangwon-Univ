#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void brighten_image(char* p, int n) {
    for (int i = 0; i < n; ++i) {
        ++p[i];
        if (p[i] > 9) p[i] = 9;
    }
}

void print_image(char* p, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", p[i * n + j]);
        }
        printf("\n");
    }
}

int main(void) {
    char image[100];
    for (int i = 0; i < 100; ++i) image[i] = 0; 
    image[55] = 9;

    printf("원본영상 : \n");
    print_image(image, 10);

    printf("밝은영상 : \n");
    brighten_image(image, 100);
    print_image(image, 10);

    return 0;
}
