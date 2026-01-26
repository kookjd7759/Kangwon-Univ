#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

void get(double value, int* i_part, double* f_part) {
    printf("전달받은 실수 = %lf\n", value);
    *i_part = (int)value;
    *f_part = value - (int)value;
}

int main(void) {
    double value = 3.14, f_part;
    int i_part;
    get(value, &i_part, &f_part);
    printf("정수부 = %d\n", i_part);
    printf("소수부 = %lf\n", f_part);


    return 0;
}
