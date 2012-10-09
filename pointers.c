#include <stdio.h>

int main(int argc, char *argv[])
{
    int a = 10;
    int b = 20;
    int *ptr = &a;
    *ptr = 50;
    printf("a is %d\n", a);
    printf("a is stored at %p\n", ptr);
    printf("a is stored at %p\n", &a);
    printf("a is stored at %p\n", (void *)&a);
    ptr = &b;
    *ptr = 70;
    printf("b is %d\n", b);

    int *ptr2 = &a;
    printf("ptr1 -> %p\n", ptr);
    printf("ptr2 -> %p\n", ptr2);
    printf("Address at ptr1 has value %d\n", *ptr);
    printf("Address at ptr2 has value %d\n", *ptr2);

    ptr2 = ptr;
    printf("ptr1 -> %p\n", ptr);
    printf("ptr2 -> %p\n", ptr2);
    printf("Address at ptr1 has value %d\n", *ptr);
    printf("Address at ptr2 has value %d\n", *ptr2);

    printf("a is %d\n", a);
    printf("b is %d\n", b);
    *ptr2 = 100;
    printf("a is %d\n", a);
    printf("b is %d\n", b);


    int my_array[] = {1, 5, 9, -6, 10};
    int *arr_ptr = &my_array[0];
    int i = 0;
    for(i=0; i<5; i++)
    {
        printf("Number %d is %d\n", i, *(arr_ptr+i));
    }

    int *arr_ptr2 = my_array; //c standards say &my_array[0] is equivalent to my_array
    int j = 0;
    for(j=0; j<5; j++)
    {
        printf("Number %d is %d\n", j, *arr_ptr2++);
    }
    return 0;
}
