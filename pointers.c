#include <stdio.h>

int main(int argc, char *argv[])
{
    int a = 10;
    int b = 20;
    int *ptr = &a;
    *ptr = 50;
    printf("a is %d\n", a);
    printf("a is stored at %p\n", ptr);
    printf("a is stored at %p\n", &a);
    printf("a is stored at %p\n", (void *)&a);
    ptr = &b;
    *ptr = 70;
    printf("b is %d\n", b);
    return 0;
}
