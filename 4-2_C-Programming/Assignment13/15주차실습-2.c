#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct course { char subject[30]; double marks; };

int main(int argc, char* argv[]) {
    printf("구조체의 개수 : ");
    int n; scanf_s("%d", &n);
    struct course* courses = (struct course*)malloc(100 * sizeof(struct course));
    for (int i = 0; i < n; ++i) {
        printf("과목 이름과 성적을 입력하시오: ");
        scanf("%s", courses[i].subject);
        scanf("%lf", &courses[i].marks);
    }
    printf("저장된 정보 출력: \n");
    for (int i = 0; i < n; ++i) {
        printf("%s \t %lf\n", courses[i].subject, courses[i].marks);
    }
    free(courses);
    return 0;
}
