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

    char chars[] = {'a', 'k', 's', '\0', 'h'};
    int num_char = sizeof(chars)/sizeof(char);
    printf("There are %d characters\n", num_char);
    printf("chars is %s\n", chars);

    for(i=0; i<num_char; i++)
    {
        printf("char %d is %c\n", i, chars[i]);
    }

    printf("printed chars\n");

    char *name = "akshar";
    printf("Size of name is %d\n", sizeof(name));
    printf("Name is %s\n.Num of chars in name is %d\n", name, (sizeof(name)/sizeof(char)));

    char another[] = "shabda";
    int another_size = sizeof(another)/sizeof(char);
    printf("size of another is %d\n. num of char is %d\n", sizeof(another), another_size);

    char *another1 = "shabda";
    int another1_size = sizeof(another1)/sizeof(char);
    printf("size of another1 is %d\n. num of char is %d\n", sizeof(another1), sizeof(another1)/sizeof(char));

    for(i=0; i<another_size-1; i++)
    {
        printf("another chars are %c\n", another[i]);
    }

    for(i=0; i<another1_size-1; i++)
    {
        printf("another1 chars are %c\n", another1[i]);
    }

    printf("another is %s\n", another);
    printf("another1 is %s\n", another1);

    return 0;
}
