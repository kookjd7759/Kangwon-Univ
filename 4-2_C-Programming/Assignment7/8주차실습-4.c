#include <stdio.h>
#include <math.h>

int main(void) {
    double x[5];
    double sum = 0.0;
    for (int i = 0; i < 5; i++) {
        printf("실수를 입력하시오:");
        scanf_s("%lf", &x[i]);
        sum += x[i];
    }
    double mean = sum / 5.0;
    printf("평균: %lf\n", mean);

    double variance = 0.0, std_dev;
    for (int i = 0; i < 5; i++)
        variance += pow(x[i] - mean, 2);

    variance /= 5.0;
    std_dev = sqrt(variance);

    printf("표준 편차: %lf\n", std_dev);

    return 0;
}
