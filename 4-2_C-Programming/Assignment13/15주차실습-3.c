#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define DEBUG 1

float calc_array_avg(int num[]) {
#ifdef DEBUG
    printf("배열의 평균을 계산합니다.\n");
    printf("calc_array_avg()\n");
    for (int i = 0; i < 10; i++) printf("%d ", num[i]);
#endif
    float result = 0;
    for (int i = 0; i < 10; i++) {
        result += num[i];
#ifdef DEBUG
        printf("%d을 더하는 중\n", num[i]);
#endif
    }

    return result / 10;
}

int main(void) {
    int n[10];
    for (int i = 0; i < 10; i++) n[i] = i + 1;
    printf("평균 = %f", calc_array_avg(n));
    return 0;
}
