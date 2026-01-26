#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void print_array(int* A, int size) {
    printf("print_array()\n");
    for (int i = 0; i < size; ++i) printf("%d ", A[i]);
    printf("\n");
}
int get_array_sum(int* A, int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) sum += A[i];
    return sum;
}

int main(void) {
    int A[10] = { 1,2,3,4,5,6,7,8,9,0 };
    int size = 10;
    print_array(A, size);
    printf("배열 요소의 합 = %d", get_array_sum(A, size));

    return 0;
}
