#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

bool isPalindrome(char* word) {
    int n = strlen(word);

    for (int i = 0; i < n / 2; i++) 
        if (word[i] != word[n - 1 - i]) 
            return false;
    return true;
}

int main(void) { 
    while (true) {
        char word[100];

        printf("회문 검사 단어 입력(종료:Ctrl + C) >> ");
        scanf("%s", &word);
        printf("'%s'은 회문", word);
        printf(isPalindrome(word) ? "임.\n" : "이 아님.\n");
    }
}
