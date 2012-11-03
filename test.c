#include <stdio.h>
#include "function1.h"

typedef void (*increase)(int number);

void increase_1(int number)
{
    printf("Number is %d\n", (number+1));
}

void increase_2(int number)
{
    printf("Number is %d\n", (number+2));
}

void use_increase(int number, increase fun)
{
    fun(number);
}

int main(int argc, char *argv[])
{
    /*printf("Hello World!\n");
    printf("Number of arguments is %d\n", argc);

    int i =0;
    for(i=0; i<argc; i++)
    {
        printf("Argument %d is %s\n", i, argv[i]);
    }

    char **some = argv;
    char *addr = *some;
    printf("Address of some is %p\n", some);
    printf("Address of first argument is %p\n", *some);
    printf("address first argument is %p\n", addr);
    printf("first argument is %s\n", addr);
    printf("first character of first argument is %c\n", *addr);
    printf("address first argument is %p\n", &argv[0]);*/

    /*int a = 10;
    int *ptr = &a;
    printf("a is %d\n", a);
    *ptr = 20;
    printf("a is %d\n", a);*/

    //use_increase(5, increase_1);
    //use_increase(5, increase_2);

    increment(13);
    return 0;
}
