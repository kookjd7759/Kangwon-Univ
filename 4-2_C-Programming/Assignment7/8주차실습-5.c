#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int main(void) {
	
	int direction = 5; // 초기 위치
	char tile[10];
	for (int i = 0; i < 10; ++i) tile[i] = '_';
	tile[direction] = '*';
	srand((unsigned int)time(NULL));
	while (!_kbhit()) {
		for (int i = 0; i < 10; ++i)
			printf("%c ", tile[i]);
		printf("\n");

		tile[direction] = '_';
		direction += (rand() % 2 == 0 ? -1 : 1);
		if (direction < 0) direction = 0;
		if (direction > 9) direction = 9;
		tile[direction] = '*';
	}
}
