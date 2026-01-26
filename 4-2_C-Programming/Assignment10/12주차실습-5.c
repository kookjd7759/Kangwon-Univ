#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

void XORCipher(char* data, char* key, int dataLen, int keyLen, char* output) {
    for (int i = 0; i < dataLen; i++) 
        output[i] = data[i] ^ key[i % keyLen];
    output[dataLen] = '\0';
}

int main(void) {
    char text[] = "This is a house.";
    char key[] = "123456";
    char output1[100], output2[100];

    int dataLen = strlen(text);
    int keyLen = strlen(key);

    printf("암호화 전의 문자열 = %s\n", text);
    printf("암호화 키 = %s\n", key);

    XORCipher(text, key, dataLen, keyLen, output1);
    printf("암호화 후의 문자열 = %s\n", output1);

    XORCipher(output1, key, dataLen, keyLen, output2);
    printf("복호화 후의 문자열 = %s\n", output2);
}
