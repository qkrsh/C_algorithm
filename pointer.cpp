#include <stdio.h>

int main(void) {
    /*포인터 개념 잡기*/

    int a = 5;
    int* ptr;
    ptr = &a;

    printf("%p\n", &a);
    printf("%d\n", a);
    printf("%p\n", ptr);
    printf("%d\n", *ptr);

    int b = 3;
    int c = 4;
    int* t;
    t = &b;
    int* q;
    q = &c;

    int temp = *t;
    *t = *q;
    *q = temp;

    printf("%d\n", b);
    printf("%d\n", c);

}