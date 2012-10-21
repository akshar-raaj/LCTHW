#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <errno.h>

void die(char *message)
{
    if(errno)
    {
        perror(message);
    }
    else
    {
        printf("Error: %s\n", message);
    }
    exit(1);
}

int main(int argc, char *argv[])
{
    if(argc<2)
    {
        die("USAGE: ./ex18 <num> <num> <num> .... <num>");
    }

    int count = argc-1;
    int *numbers = malloc(count * sizeof(int));
    assert(numbers!=NULL);

    int i = 0;
    for(i=1; i<=count; i++)
    {
        numbers[i-1] = atoi(argv[i]);
    }

    for(i=0; i<count; i++)
    {
        printf("Number is %d\n", numbers[i]);
    }

    free(numbers);
    return 0;
}
