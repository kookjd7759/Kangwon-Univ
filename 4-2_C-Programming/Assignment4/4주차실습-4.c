#include <stdio.h>

int main(void) {
    double x;
    printf("x의 값을 입력하시오: ");
    scanf_s("%lf",  &x);
    printf("수식의 값은 %f입니다.", ((x * x * x - 20.0) / (x - 7.0)));
    return 0;
}
