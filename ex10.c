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
        "Andhra Pradesh", "Orissa"};

    int num_states = 4;
    for(i=0; i<num_states; i++)
    {
        printf("State %d is %s\n", i, states[i]);
    }
    
    return 0;
}
