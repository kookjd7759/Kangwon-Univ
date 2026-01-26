#include <stdio.h>

int main(void) {
    int a, b;
    char exp;
    printf("수식을 입력하시오: ");
    scanf_s("%d %c %d", &a, &exp, 1, &b);
    switch (exp) {
    case '+': printf("%d", a + b); break;
    case '-': printf("%d", a - b); break;
    case '*': printf("%d", a * b); break;
    case '/': printf("%d", a / b); break;
    default: break;
    }

    return 0;
}
