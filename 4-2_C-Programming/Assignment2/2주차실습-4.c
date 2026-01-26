#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	printf("반지름을 입력하시오 : ");
	float r; scanf_s("%f", &r);
	printf("원의 면적 : %f\n", (3.14 * r * r));
	printf("원의 둘레 : %f", (2.0 * 3.14 * r));
	return 0;
}