#include <stdio.h>

int main(void) {
    double kg, m;
    printf("체중을 입력하시오: ");
    scanf_s("%lf",  &kg);
    printf("신장을 입력하시오(단위: 미터): ");
    scanf_s("%lf", &m);
    printf("BMI: %.2f", kg / (m * m));
    return 0;
}
