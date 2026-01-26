#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int a[10]; // 횟수를 저장할 배열 선언
    for (int i = 0; i < 10; ++i) a[i] = 0;

    srand((unsigned int)time(NULL));
    for (int i = 0; i < 100; i++) ++a[rand() % 10]; // 100회 난수 생성

    int maxi_idx = 0;
    for (int i = 0; i < 10; i++) if (a[i] > a[maxi_idx]) maxi_idx = i;

    printf("가장 많이 생성된 수: %d", maxi_idx + 1);

    return 0;
}
