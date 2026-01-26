#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct item { char name[30]; float price; int qty; float amount; };

int main(void) {
    struct item items[3];

    for (int i = 0; i < 3; ++i) {
        printf("상품의 이름: "); scanf("%s", items[i].name);
        printf("상품의 가격: "); scanf("%f", &items[i].price);
        printf("상품의 개수: "); scanf("%d", &items[i].qty);

        items[i].amount = items[i].price * items[i].qty;

        printf("===================\n");
    }
    printf("===================\n\n");

    for (int i = 0; i < 3; ++i) {
        printf("상품의 이름: %s\n", items[i].name);
        printf("상품의 가격: %.6f\n", items[i].price);
        printf("상품의 개수: %d\n", items[i].qty);
        printf("상품의 재고액: %.6f\n\n", items[i].amount);
        printf("===================\n");
    }

    return 0;
}
