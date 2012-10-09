#include <stdio.h>


void copy(char *destination, char *source)
{
    while(*source != '\0')
    {
        *destination++ = *source++;
    }
    *destination = '\0';
}

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

    char third[] = "akshar raaj";
    char fourth[20];
    copy(fourth, third);
    printf("Fourth is %s\n", fourth);

    return 0;
}
