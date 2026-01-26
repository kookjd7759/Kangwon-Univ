#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

void quadratic(int a, int b, int c, double* xplus, double* xminus) {
    *xminus = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
    *xplus = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
}

int main(void) {
    int a = 10, b = 40, c = 30;
    double xplus = 0, xminus = 0;
    quadratic(a, b, c, &xplus, &xminus);
    printf("첫번째 실근: %lf\n", xplus);
    printf("두번째 실근: %lf\n", xminus);

    return 0;
}
