#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<string>

void divide(char* search, char* first, char* second) {

    int i;

    for (i = 0; i < strlen(search); i++) {
        if (search[i] == '*') {
            break;
        }
    }

    for (int c = 0; c < i; c++) {
        first[c] = search[c];
    }

    first[i] = '\0';
    if (i == strlen(search)) {
        second[0] = '\0';
     }
    else
    {
        int e = 0;
        for (int d = i + 1; d < strlen(search); d++, e++) {
            second[e] = search[d];
        }
        second[strlen(search) - i - 1] = '\0';
    }
    printf("search_loc: %d\n", i);
    printf("first: %s\n", first);
    printf("second: %s\n", second);

}

bool qwe(char* d, char* e) {
    int len = strlen(e);
    for (int a = 0; a < len; a++) {
        if (d[a] != e[a]) {
            return false;
        }
    }
    return true;
}

int partial_match(char* str, char* first, char* second) {
    int count = 0;

    int a = strlen(str);
    for (int i = 0; i < a; i++) 
    {
        if (qwe(&str[i], first))
        {
            if (strlen(second) == 0) {
                count++;
            }
            else 
            {
                for (int q = i + strlen(first); q < a; q++)
                {
                    if (qwe(&str[q], first))
                    {
                        break;
                    }

                    if (qwe(&str[q], second))
                    {
                        count++;
                    }
                }
            }
        }
        
    }
    return count;
}

int main()
{
    char str[] = "My name is hong gil dong. My brother is hong je dong.My sister is hong gilja, and her friend is hongdong.";
    char search[] = "hong*dong";
    printf("str: %s\n", str);
    printf("search: %s\n", search);

    char first[120];
    char second[120];

     divide(search,first,second);
     int count = partial_match(str, first, second);

    printf("\n%d\n\n", count);

    return 0;
}