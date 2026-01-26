#include <stdio.h>

int main(void) {
    int num;
    printf("과세 표준을 입력하시오(만원): ");
    scanf_s("%d",  &num);
    
    int a = 1000 * 8 / 100;
    int b = 3000 * 17 / 100;
    int c = 4000 * 26 / 100;
    int tax = 0;
    if (num <= 1000) 
        tax = num * 8 / 100;
    else if (num <= 4000) 
        tax = a + (num - 1000) * 17 / 100;
    else if (num <= 8000) 
        tax = a + b + (num - 4000) * 26 / 100;
    else 
        tax = a + b + c + (num - 8000) * 35 / 100;

    printf("소득세는 %d만원입니다.\n", tax);

    return 0;
}
