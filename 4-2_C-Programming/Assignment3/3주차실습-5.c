#include <stdio.h>

int main(void) {
    short age;
    int id;
    long long products;
    double stars;
    char word;

    printf("나이를 입력하시오: ");
    scanf_s("%hd", &age);

    printf("직원 아이디를 입력하시오: ");
    scanf_s("%d", &id);

    printf("생산량을 입력하시오: ");
    scanf_s("%lld", &products);

    printf("별의 개수를 입력하시오: ");
    scanf_s("%lf", &stars);

    printf("글자를 입력하시오: ");
    getchar();
    word = getchar();

    printf("나이: %hd\n", age);
    printf("아이디: %d\n", id);
    printf("생산량: %lld\n", products);
    printf("별의 개수: %lf\n", stars);
    printf("글자: %c\n", word);

    return 0;
}
