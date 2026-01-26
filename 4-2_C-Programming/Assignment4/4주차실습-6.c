#include <stdio.h>

int main(void) {
    int num;
    printf("숫자를 입력하시오: ");
    scanf_s("%d",  &num);
    printf("LSB는 %d", (num & 0x01));
    return 0;
}
