#include <stdio.h>

int main(void) {
    int price;
    double per;
    printf("상품 가격을 입력하시오: ");
    scanf_s("%d",  &price);
    printf("할인률을 입력하시오: ");
    scanf_s("%lf", &per);
    printf("할인된 가격은 %.2f입니다.", price - (price * per / 100.0));
    return 0;
}
