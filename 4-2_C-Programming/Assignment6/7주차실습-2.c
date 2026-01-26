#include <stdio.h>

int main(void) {
	printf("정수를 입력하시오: ");
	int n; scanf_s("%d", &n);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j)
			printf("%d ", j);
		printf("\n");
	}
}
