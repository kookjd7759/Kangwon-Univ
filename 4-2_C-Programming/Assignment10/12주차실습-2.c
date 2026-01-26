#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    printf("숫자, 소문자, 대문자가 포함되도록 암호를 만드세요.\n");
    while (true) {
        printf("암호 입력 >> ");
        char line[100];
        gets_s(line, sizeof(line));

        bool hasDigit = false, hasLower = false, hasUpper = false;
        for (int i = 0; i < strlen(line); i++) {
            if (isdigit(line[i])) hasDigit = true;
            if (islower(line[i])) hasLower = true;
            if (isupper(line[i])) hasUpper = true;
        }

        if (hasUpper && hasLower && hasDigit) {
            printf("암호 생성이 완료되었습니다.\n");
            break;
        }
        else {
            printf("생성 불가한 암호입니다. 대문자, 소문자, 숫자가 모두 포함하여 다시 만드세요!\n\n");
        }
    }
}
