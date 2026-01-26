#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int a, b;
char c;

int add() { return a + b; }
int sub() { return a - b; }
int mult() { return a * b; }
int div() { return a / b; }

void calculate(char c) {
	static int cnt_add = 0, cnt_sub = 0, cnt_mult = 0, cnt_div = 0;
	printf("연산 결과: ");
	if (c == '+') {
		++cnt_add;
		printf("%d\n", add());
		printf("덧셈은 총 %d번 호출되었습니다.\n", cnt_add);
	}
	else if (c == '-') {
		++cnt_sub;
		printf("%d\n", sub());
		printf("뺄셈은 총 %d번 호출되었습니다.\n", cnt_sub);
	}
	else if (c == '*') {
		++cnt_mult;
		printf("%d\n", mult());
		printf("곱셈은 총 %d번 호출되었습니다.\n", cnt_mult);
	}
	else if (c == '/') {
		++cnt_div;
		printf("%d\n", div());
		printf("나눗셈은 총 %d번 호출되었습니다.\n", cnt_div);
	}
}

int main(void) {
	while (true) {
		printf("연산을 입력하시오(종료는 Ctrl-Z): ");
		scanf("%d %c %d", &a, &c, &b);
		calculate(c);
	}

	return 0;
}