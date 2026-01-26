#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
    char name[100];
    int age;
    double salary;

    printf("직원 이름: "); scanf("%s", name);
    printf("나이: "); scanf("%d", &age);
    printf("월급: "); scanf("%lf", &salary);

    FILE* fp = fopen("employee.txt", "w");
    if (fp == NULL) {
        printf("ERROR::Can't open the file.\n");
        return -1;
    }

    fprintf(fp, "이름 = %s\n", name);
    fprintf(fp, "나이 = %d\n", age);
    fprintf(fp, "월급 = %.6f\n", salary);

    fclose(fp);

    return 0;
}
