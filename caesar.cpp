#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#define ENCRYP 3

void encry(char* str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'W')
            str[i] += ENCRYP;
        else if (str[i] == 'X' )
            str[i] = 'A';
        else if (str[i] == 'Y')
            str[i] = 'B';
        else if (str[i] == 'Z')
            str[i] = 'C';
        else if (str[i] >= 'a' && str[i] <= 'w')
            str[i] += ENCRYP;
        else if (str[i] == 'x')
            str[i] = 'a';
        else if (str[i] == 'y')
            str[i] = 'b';
        else if (str[i] == 'z')
            str[i] = 'c';
        i++;
    }
}

void dencry(char* str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'D' && str[i] <= 'Z')
            str[i] -= ENCRYP;
        else if (str[i] == 'A')
            str[i] = 'X';
        else if (str[i] == 'B')
            str[i] = 'Y';
        else if (str[i] == 'C')
            str[i] = 'Z';
        else if (str[i] >= 'd' && str[i] <= 'z')
            str[i] -= ENCRYP;
        else if (str[i] == 'a')
            str[i] = 'x';
        else if (str[i] == 'b')
            str[i] = 'y';
        else if (str[i] == 'c')
            str[i] = 'z';
        i++;
    }
}

char* decrypt(char* base, const char* src) {

    char* origin = base;
    for (; *src; src++, base++) {
        if (isupper(*src)) {
            *base = (*src - 'A' + 23) % 26 + 'A';
        }
        else if (islower(*src))
            *base = (*src - 'a' + 23) % 26 + 'a';
        else
            *base = *src;
    }
    *base = '\0';
    return origin;
}

bool Read_file(const char* fname, char a[12][200]) {

    FILE* pFile;
    pFile = fopen(fname, "r");

    if (pFile == NULL)
    {
        printf("Cannot_open the file\n");
        return false;
    }
    for (int i = 0; i < 12; i++) {
        fgets(a[i], 200, pFile);
    }
    
    fclose(pFile);
    return true;
}


bool Write_file(const char* fname, char b[12][200]) {

    FILE* pFile;
    pFile = fopen(fname, "w");

    if (pFile == NULL)
    {
        printf("Cannot_open the file\n");
        return false;
    }
  
    for (int i = 0; i < 11; i++) {
            fputs(b[i],pFile);
    }

    fclose(pFile);
    return true;
}

int main()
{   
    char a[12][200];
    char fname[64] = "original.txt";
    char fname2[64] = "cypher.txt";
    char fname3[64] = "decrypted.txt";
    
    if (!Read_file(fname, a)) {
        return -1;
    }
    for(int i=0;i<12;i++){
        encry(a[i]);
    }
    if (!Write_file(fname2, a)) {
        return -1;
    }

    if (!Read_file(fname2, a)) {
        return -1;
    }
    for (int i = 0; i < 12; i++) {
        dencry(a[i]);
    }
    if (!Write_file(fname3, a)) {
        return -1;
    }
}