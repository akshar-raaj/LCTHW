#include <stdio.h>
#include <ctype.h>

int can_print_it(char ch);
void print_letters(char argv[]);

void print_arguments(int argc, char *argv[])
{
    int i = 0;
    for(i=0; i<argc; i++)
    {
        print_letters(argv[i]);
    }
}

void print_letters(char argv[])
{
    int i = 0;
    for(i=0; argv[i] != '\0'; i++)
    {
        if(can_print_it(argv[i]))
        {
            printf("'%c' = %d\n", argv[i], argv[i]);
        }
    }
}

int can_print_it(char ch)
{
    return isalpha(ch) || isblank(ch);
}

int main(int argc, char *argv[])
{
    print_arguments(argc, argv);
    return 0;
}
