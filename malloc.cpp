#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int main()
{

    char temp[80];  //�ӽù迭
    char* str[3];   //�����Ҵ� ���� ������ �迭
    int i = 0;

    for (i = 0; i < 3; i++) {
        printf("enter the name of animal\n");
        gets_s(temp);
        str[i] = (char*)malloc(strlen(temp) + 1);
        strcpy(str[i], temp);
    }

    for (i = 0; i < 3; i++) {
        printf("%s\n",str[i]);
    }

    for (i = 0; i < 3; i++) {
        free(str[i]);
    }

    return 0;
}