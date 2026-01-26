#include <stdio.h>

int main(void) {
    char color;
    printf("신호등의 색깔 입력 (R, G, Y): ");
    scanf_s("%c",  &color, 1);
    
    if (color == 'R' || color == 'r') printf("정지!");
    else if (color == 'G' || color == 'g') printf("진행");
    else if (color == 'Y' || color == 'y') printf("주의");
    else printf("신호등의 색깔이 아닙니다.");

    return 0;
}
