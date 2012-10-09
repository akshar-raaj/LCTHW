#include <stdio.h>

int main(int argc, char *argv[])
{
    char first[] = "Hello World!";
    char second[50];
    printf("First is %s\n", first);

    char *fp = first;
    char *sp = second;
    char each_char;

    while(*fp!='\0')
    {
        each_char = *fp;
        *sp = each_char;
        fp++;
        sp++;
    }
    *sp = '\0';
    printf("Second is %s\n", second);
    return 0;
}
