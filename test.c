#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("Hello World!\n");
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
    printf("address first argument is %p\n", &argv[0]);

    return 0;
}
