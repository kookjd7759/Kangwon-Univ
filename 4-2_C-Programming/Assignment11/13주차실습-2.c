#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

struct employee { int number; char name[20]; int age; };

int main(void) {
	struct employee employees[10];
	employees[0].number = 1; strcpy(employees[0].name, "짱구"); employees[0].age = 5;
	employees[1].number = 2; strcpy(employees[1].name, "국동균"); employees[1].age = 25;
	employees[2].number = 3; strcpy(employees[2].name, "배정남"); employees[2].age = 42;
	employees[3].number = 4; strcpy(employees[3].name, "우도환"); employees[3].age = 33;
	employees[4].number = 5; strcpy(employees[4].name, "이민철"); employees[4].age = 29;
	employees[5].number = 6; strcpy(employees[5].name, "백가림"); employees[5].age = 20;
	employees[6].number = 7; strcpy(employees[6].name, "삼겹살"); employees[6].age = 30;
	employees[7].number = 8; strcpy(employees[7].name, "족발"); employees[7].age = 50;
	employees[8].number = 9; strcpy(employees[8].name, "라면"); employees[8].age = 28;
	employees[9].number = 10; strcpy(employees[9].name, "강아지"); employees[9].age = 3;

	for (int i = 0; i < 10; ++i) {
		if (20 <= employees[i].age && employees[i].age <= 30)
			printf("[번호] %d [이름] %s [나이] %d\n",
				employees[i].number, employees[i].name, employees[i].age);
	}
}