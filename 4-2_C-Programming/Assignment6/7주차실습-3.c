#include <stdio.h>

int main(void) {
	printf("몇 번째 항까지 구할까요? ");
	int a = 0, b = 1, n; scanf_s("%d", &n);
	for (int i = 0; i <= n; ++i) {
		/*
		* n번째 항까지 구한다는 문제의 조건에서 
		* 첫째항 0을 1번째라고 계산한다면 i < n 이 맞지만
		* 문제의 예시 출력은 첫째항 0을 0번째로 계산하여
		* 10 입력시 55까지 출력하기 때문에 이에 맞추어 i <= n 로 작성함
		*/
		if (i == 0) printf("0, ");
		else if (i == 1) printf("1, ");
		else {
			printf("%d, ", a + b);
			int temp = a + b;
			a = b;
			b = temp;
		}
	}
}
