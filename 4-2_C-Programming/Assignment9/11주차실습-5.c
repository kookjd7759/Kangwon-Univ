#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void array_add(int a[], int b[], int c[], int size) {
	for (int i = 0; i < size; ++i)
		c[i] = a[i] + b[i];
}

void array_print(const char* name, int* a, int size) {
	printf("%s = ", name);
	for (int i = 0; i < size; ++i) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main(void) {
	int A[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int B[10] = { 10,9,8,7,6,5,4,3,2,1 };
	int C[10], size = 10;
	array_print("기본급", A, 10);
	array_print("보너스", B, 10);

	array_add(A, B, C, size);
	array_print("총액", C, 10);
}
