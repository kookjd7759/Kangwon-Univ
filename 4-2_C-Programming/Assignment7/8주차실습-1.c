#include <stdio.h>

int main(void) {
	int arr[3][4] = {
		{1, 30, 10, 11},
		{2, 40, 90, 32},
		{3, 70, 65, 56}
	};
	// pdf 예제 출력에서와 문제에서 제시하는 것과 맞지 않아서
	// 다음과 같은 평균의 종류를 모두 구하였습니다.

	double sum = 0.0;
	for (int i = 0; i < 3; ++i)
		for (int j = 1; j < 4; ++j)
			sum += (double)arr[i][j];
	printf("전체 학생의 평균 점수: %lf\n", sum / 9.0);

	for (int i = 0; i < 3; ++i) {
		sum = 0.0;
		for (int j = 1; j < 4; ++j)
			sum += (double)arr[i][j];
		printf("학생 %d의 평균 점수: %lf\n", i + 1, sum / 3.0);
	}
}
