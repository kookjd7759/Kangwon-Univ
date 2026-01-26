#include <stdio.h>

int main(void) {
	int r, c; 
	printf("행 개수="); scanf_s("%d", &r);
	printf("열 개수="); scanf_s("%d", &c);
	
	int arr1[10][10];
	int arr2[10][10];
	int result[10][10];

	printf("첫 번째 행렬 입력=\n");
	for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j)
		scanf_s("%d", &arr1[i][j]);

	printf("두 번째 행렬 입력=\n");
	for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j)
		scanf_s("%d", &arr2[i][j]);

	for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j) {
		result[i][j] = 0;
		for (int k = 0; k < c; ++k) result[i][j] += arr1[i][k] * arr2[k][j];
	}

	printf("행렬 곱 결과:\n");
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j)
			printf("%d ", result[i][j]);
		printf("\n");
	}
}
