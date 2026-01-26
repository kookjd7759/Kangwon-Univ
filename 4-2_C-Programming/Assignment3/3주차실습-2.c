#include <stdio.h>

const double PI = 3.141592;

int main(void) {
	printf("반지름을 입력하시오: ");
	double r; scanf_s("%lf", &r);

	printf("구의 표면적: %f\n", (4.0 * PI * r * r));
	printf("구의 부피: %f", (4.0 / 3.0 * PI * r * r * r));
	return 0;
}