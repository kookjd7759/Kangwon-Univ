#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int price, amount;
	printf("상품의 가격을 입력하시오 : ");
	scanf_s("%d", &price);
	printf("상품의 개수를 입력하시오 : ");
	scanf_s("%d", &amount);
	printf("총 가격은 %d원 입니다.", price * amount);
	return 0;
}