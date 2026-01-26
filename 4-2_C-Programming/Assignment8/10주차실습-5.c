#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void func(int n) {
    if (n < 10) {
        printf("%d ", n);
        return;
    }
    func(n / 10);
    printf("%d ", n % 10);
}

int main(void) {
    int n;
    printf("정수를 입력하시오: ");
    scanf("%d", &n);
    func(n);
    return 0;
}
