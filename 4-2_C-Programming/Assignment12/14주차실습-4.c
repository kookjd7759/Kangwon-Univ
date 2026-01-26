#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand((unsigned int)time(NULL));

    FILE* fp_txt, *fp_bin;
    fp_txt = fopen("sample1.txt", "w");
    if (fp_txt == NULL) {
        printf("ERROR::Can't open the file.\n");
        return -1;
    }

    fp_bin = fopen("sample2.bin", "wb");
    if (fp_bin == NULL) {
        printf("ERROR::Can't open the file.\n");
        return -1;
    }

    for (int i = 0; i < 1000; i++) {
        int random = rand();
        fprintf(fp_txt, "%d ", random);
        fwrite(&random, sizeof(int), 1, fp_bin);
    }

    fclose(fp_txt);
    fclose(fp_bin);

    return 0;
}
