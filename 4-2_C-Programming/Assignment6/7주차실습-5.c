#include <stdio.h>
#include <time.h>

int main(void) {
    int sticks = 12;
    int user, computer;

    srand((unsigned)time(NULL));

    printf("=== NIM 게임 ===\n");
    while (sticks > 0) {
        printf("현재 스틱 개수: %d\n", sticks);

        printf("몇 개의 스틱을 가져가시겠습니까?: ");
        scanf_s("%d", &user);

        if (user < 1 || user > 3) {
            printf("1개부터 3개까지 가능합니다.\n\n");
            continue;
        }

        sticks -= user;

        if (sticks <= 0) {
            printf("당신이 마지막 스틱을 가져갔습니다. 당신의 패배입니다!\n");
            break;
        }

        computer = rand() % 4; // 0 ~ 3 사이 즉, 0, 1, 2, 3 중 하나여야 하기 때문에 %4 연산을 함
        // 예시에서 컴퓨터가 0개의 스틱을 가져가는 예시가 있어서 0도 포함시켜서 작성
        if (computer > sticks)
            computer = sticks;

        printf("**컴퓨터는 %d개의 스틱을 가져갔습니다.\n", computer);
        sticks -= computer;

        if (sticks <= 0) {
            printf("컴퓨터가 마지막 스틱을 가져갔습니다. 당신의 승리입니다!\n");
            break;
        }

        printf("\n");
    }
}
