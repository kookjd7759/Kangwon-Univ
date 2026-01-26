#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
	char line[100];
	printf("텍스트를 입력하시오: ");
	gets_s(line, sizeof(line));

	for (int i = 0; i < strlen(line); ++i) line[i] = toupper(line[i]);

	printf("대문자 출력: %s", line);
}
