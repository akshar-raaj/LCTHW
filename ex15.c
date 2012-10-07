#include <stdio.h>

int main(int argc, char *argv[])
{
    char *name = "akshar";
    printf("Name is %s\n", name);

    printf("First character is %c\n", *name);
    printf("Second character is %c\n", *(name+1));

    printf("First character is %c\n", name[0]);
    printf("Second character is %c\n", name[1]);

    int nums[] = {12, 34, 5, 67, 81};
    int i;

    int count = sizeof(nums)/sizeof(int);
    for(i=0; i<count; i++)
    {
        printf("Num %d is %d\n", i, nums[i]);
    }

    int *num_p = nums;

    printf("First number is %d\n", *num_p);
    printf("Second number is %d\n", *(num_p+1));

    printf("First number is %d\n", num_p[0]);
    printf("Second number is %d\n", num_p[1]);

    return 0;
}
