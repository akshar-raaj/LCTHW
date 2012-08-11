#include <stdio.h>

int main(int args, char *argv[])
{
    int areas[] = {10, 12, 13, 14, 20};
    char name[] = "Zed";
    char full_name[] = {
        'Z', 'e', 'd',
        ' ', 'A', '.', ' ',
        'S', 'h', 'a', 'w', '\0'
    };

    printf("The size of an int: %u\n", sizeof(int));
    printf("The size of areas (int []): %u\n", sizeof(areas));
    printf("The number of ints in areas: %u\n", sizeof(areas)/sizeof(int));
    printf("The first area is %d, the second %d.\n", areas[0], areas[1]);

    printf("The size of a char: %u\n", sizeof(char));
    printf("The size of name(char []): %u.\n", sizeof(name));
    printf("the number of chars: %d\n", sizeof(name)/sizeof(char));

    printf("The size of full name (char[]) %u.\n", sizeof(full_name));

    printf("name=\"%s\" and full_name=\"%s\"\n", name, full_name);
    areas[0] = 85;
    areas[10] = 56;
    printf("areas0 is %d .size is %u. area10 is %d\n", areas[0], sizeof(areas), areas[10]);
    printf("%d %d %d %d %d %d\n", areas[0], areas[1], areas[2], areas[3],areas[4], areas[10]);

    return 0;
}
