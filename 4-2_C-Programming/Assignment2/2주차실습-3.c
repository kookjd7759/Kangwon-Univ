#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int x, y, z;
	printf("정수를 입력하시오 : ");
	scanf_s("%d", &x);
	printf("정수를 입력하시오 : ");
	scanf_s("%d", &y);
	printf("정수를 입력하시오 : ");
	scanf_s("%d", &z);
	float avg = (x + y + z) / 3;
	printf("평균은 %f 입니다.", avg);
	return 0;
}