#include <stdio.h>

int main(void) {
	float distance, h, m, s;
	printf("거리를 미터로 입력하시오: "); scanf_s("%f", &distance);
	printf("시간을 입력하시오: "); scanf_s("%f", &h);
	printf("분을 입력하시오: "); scanf_s("%f", &m); h += (m / 60.0);
	printf("초를 입력하시오: "); scanf_s("%f", &s); h += (s / 3600.0);
	printf("속도: %f", (distance / h / 1000.0)); 

	return 0;
}