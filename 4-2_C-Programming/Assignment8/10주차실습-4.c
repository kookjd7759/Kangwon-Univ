#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int cal(int n) {
	if (n == 1) return 1;
	return (n * n * n) + cal(n - 1);
}

int main(void) {
	int n;
	printf("정수를 입력하시오: ");
	scanf_s("%ld", &n);
	printf("%ld", cal(n));

	return 0;
}