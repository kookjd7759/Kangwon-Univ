#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

struct complex { double real; double image; };
struct complex add_complex(struct complex x, struct complex y) {
	struct complex result;
	result.real = x.real + y.real;
	result.image = x.image + y.image;
	return result;
}

int main(void) {
	struct complex x, y;
	printf("첫번째 복소수를 입력하시오(a, b) : ");
	scanf_s("%lf %lf", &x.real, &x.image);
	printf("두번째 복소수를 입력하시오(a, b) : ");
	scanf_s("%lf %lf", &y.real, &y.image);
	struct complex add_xy = add_complex(x, y);
	printf("%.1lf + %.1lfi", add_xy.real, add_xy.image);
}