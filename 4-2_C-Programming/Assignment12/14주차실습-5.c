#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
    char name1[100], name2[100]; 
    FILE *fp1, *fp2;
    printf("첫번째 파일 이름: "); gets_s(name1, 100);
    fp1 = fopen(name1, "r");
    if (fp1 == NULL) {
        printf("ERROR::Can't open the file.\n");
        return -1;
    }

    printf("두번째 파일 이름: "); gets_s(name2, 100);
    fp2 = fopen(name2, "r");
    if (fp2 == NULL) {
        printf("ERROR::Can't open the file.\n");
        return -1;
    }

    char fname1[100];
    char fname2[100];
    char line1[1024], line2[1024];
    char* p1, * p2;
    bool isSame = true;

    while (true) {
        p1 = fgets(line1, sizeof(line1), fp1);
        p2 = fgets(line2, sizeof(line2), fp2);

        if (p1 == NULL && p2 == NULL) break;
        if (p1 == NULL && p2 != NULL) {
            isSame = false;
            while (p2 != NULL) {
                printf("<< ");
                printf(">> %s", line2);
                p2 = fgets(line2, sizeof(line2), fp2);
            }
            break;
        }
        if (p1 != NULL && p2 == NULL) {
            isSame = false;
            while (p1 != NULL) {
                printf("<< %s", line1);
                printf(">> ");
                p1 = fgets(line1, sizeof(line1), fp1);
            }
            break;
        }

        if (strcmp(line1, line2) != 0) {
            isSame = false;
            printf("<< %s", line1);
            printf(">> %s", line2);
        }
    }

    if (isSame) printf("파일은 서로 일치함\n");

    fclose(fp1);
    fclose(fp2);

    return 0;
}
