#include <stdio.h>

int main(void) {
	for (int i = 1; i <= 100; ++i) // 1부터 100까지 이므로 100도 포함
		if (i % 3 == 0)
			printf("%d ", i);
}
