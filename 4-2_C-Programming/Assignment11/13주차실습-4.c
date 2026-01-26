#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum RSP { SCISSOR = 0, ROCK = 1, PAPER = 2 };

int main(void) {
    int player, ai;

    printf("가위(0), 바위(1), 보(2)를 입력하세요: "); 
    scanf("%d", &player);

    srand(time(NULL));
    ai = rand() % 3;

    if (player == ai) {
        printf("비겼습니다.\n");
    }
    else if ((player == SCISSOR && ai == PAPER) ||
        (player == ROCK && ai == SCISSOR) ||
        (player == PAPER && ai == ROCK)) {
        printf("컴퓨터가 졌습니다.\n");
    }
    else {
        printf("컴퓨터가 이겼습니다.\n");
    }

    return 0;
}
