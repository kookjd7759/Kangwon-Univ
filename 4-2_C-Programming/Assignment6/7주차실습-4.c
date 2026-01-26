#include <stdio.h>

int main(void) {
    double sum = 0.0, divident = 4.0;
    int divisor = 1;
    int cnt = 1000000;

    for (int i = 0; i < cnt; i++) {
        sum += divident / divisor;
        divident = -1.0 * divident;
        divisor = divisor + 2;
    }

    printf("반복횟수: %d\n", cnt);
    printf("Pi = %f\n", sum);
}
