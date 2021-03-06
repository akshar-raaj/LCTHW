#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <errno.h>

typedef int (*compare)(int a, int b);

int ascending_order(int a, int b)
{
    return a-b;
}

int descending_order(int a, int b)
{
    return b-a;
}

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

int *bubble_sort(int *numbers, int count, compare cmp)
{
    int *copy = malloc(count * sizeof(int));
    memcpy(copy, numbers, count * sizeof(int));
    int i;
    int j;
    int temp;
    int is_sorted;

    for(i=0; i<count; i++)
    {
        is_sorted = 1;
        for(j=0; j<count-1-i; j++)
        {
            if(cmp(copy[j], copy[j+1]) > 0)
            {
                is_sorted = 0;
                temp = copy[j];
                copy[j] = copy[j+1];
                copy[j+1] = temp;
            }
        }
        if(is_sorted)
        {
            break;
        }
    }
    return copy;
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

    printf("Original numbers:\n");
    for(i=0; i<count; i++)
    {
        printf("Number is %d\n", numbers[i]);
    }

    int *copy = bubble_sort(numbers, count, ascending_order);

    printf("\nNumbers after sorting:\n");
    for(i=0; i<count; i++)
    {
        printf("Number is %d\n", copy[i]);
    }

    copy = bubble_sort(numbers, count, descending_order);

    printf("\nNumbers after reverse sorting:\n");
    for(i=0; i<count; i++)
    {
        printf("Number is %d\n", copy[i]);
    }

    free(numbers);
    free(copy);
    return 0;
}
