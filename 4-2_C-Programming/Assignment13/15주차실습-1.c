#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL));
    int* arr = (int*)malloc(100 * sizeof(int));
    if (arr == NULL) {
        printf("Memory Error\n");
        return -1;
    }
    for (int i = 0; i < 100; ++i) arr[i] = rand() % 100;

    int sum = 0;
    for (int i = 0; i < 100; ++i) sum += arr[i];
    printf("평균=%d", (sum / 100));

    free(arr);
    return 0;
}
