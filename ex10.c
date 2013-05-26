#include <stdio.h>

int main(int argc, char *argv[])
{
    int i =0;

    for(i=1; i<argc; i++)
    {
        printf("arg %d is %s.\n", i, argv[i]);
    }

    char *states[] = {
        "Bihar", "Jharkhand",
        "Andhra Pradesh", "Orissa", NULL, NULL, "MP"};

    int num_states = 4;
    for(i=0; i<num_states; i++)
    {
        printf("State %d is %s\n", i, states[i]);
    }

    printf("state 0 %s\n", *states);
    printf("state 0 %s\n", states[0]);
    printf("Second character of Bihar is %c\n", *(states[0]+1));
    printf("state 1 %s\n", *(states+1));

    char abc = 'A';
    printf("char %d %c\n", abc, abc);
    abc = abc+1;
    printf("char %d %c\n", abc, abc);
    char bcd = '\0';
    printf("char %d %c\n", bcd, bcd);
    bcd = bcd+1;
    printf("char %d %c\n", bcd, bcd);
    
    return 0;
}
