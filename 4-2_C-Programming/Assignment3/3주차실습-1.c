#include <stdio.h>

int main(void) {
	printf("실수를 입력하시오: ");
	float num; scanf_s("%f", &num);

	printf("지수 형식으로는 %e 입니다.", num);
	return 0;
}