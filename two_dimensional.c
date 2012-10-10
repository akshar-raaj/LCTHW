#include <stdio.h>

int main(int argc, char *argv[])
{
    int arr[2][3] = {{2,4,6}, {1,5,9}};
    int *ptr = &arr[0][0];
    printf("address of arr is %p\n", ptr);

    printf("Value at 0,0 is %d\n", *ptr);
    printf("Value at 0,1 is %d\n", *(ptr+1));
    printf("Value at 0,2 is %d\n", *(ptr+2));

    printf("Value at 1,0 is %d\n", *(ptr+3));
    printf("Value at 1,1 is %d\n", *(ptr+4));
    printf("Value at 1,2 is %d\n", *(ptr+5));

    int *ptr1 = arr[0];
    printf("arr0 refers to %d\n", *ptr1);
    
    int *ptr2 = arr[1];

    int *ptr_array[2]; 
    ptr_array[0] = ptr1;
    ptr_array[1] = ptr2;

    int **ptr_to_ptr = ptr_array;

    printf("Second element of first array %d\n", *((*ptr_to_ptr)+1));
    printf("Second element of second array %d\n", *(*(ptr_to_ptr+1)+1));

    return 0;
}
