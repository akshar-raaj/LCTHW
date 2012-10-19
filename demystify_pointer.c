#include <stdio.h>

int main(int argc, char *argv[])
{
    int a = 10;

    int *ptr = &a;

    printf("a is %d\n", a);
    printf("Address of a is %p\n", ptr);
    printf("a is %d\n", *ptr);

    int **ptr_to_ptr = &ptr; 
    printf("Address of a is %p\n", *ptr_to_ptr);
    printf("Address of ptr_to_ptr is %p\n", ptr_to_ptr);

    char arr[] = {'a', 'k', '\0'};
    printf("arr is %s\n", arr);

    char *arr1 = "akshar";
    printf("arr1 is %s\n", arr1);

    char *arr3 = arr;

    char arr2[] = "akshar";
    return 0;
}
