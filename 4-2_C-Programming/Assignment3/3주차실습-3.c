#include <stdio.h>

int main(void) {
	printf("문자를 입력하시오: ");
	char c; scanf_s(" %c", &c, 1);

	printf("아스키 코드: %d", c);
	return 0;
}