#include <stdio.h>

int main(void) {
    int num;
    printf("요일을 0(일요일)에서 6까지의 정수로 입력하시오: ");
    scanf_s("%d",  &num);
    
    if (num == 0 || num == 6) printf("주말입니다.");
    else printf("평일입니다.");

    return 0;
}
