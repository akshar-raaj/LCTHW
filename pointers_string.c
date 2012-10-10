#include <stdio.h>

int strlen_impl(char *str)
{
    int i = 0;
    while(*str != '\0')
    {
        i++;
        str++;
    }
    return i;
}

void strcat_impl(char *str1, char *str2)
{
    char arr[40];
    char *ptr = arr;
    while(*str1 != '\0')
    {
        *ptr++ = *str1++;
    }
    while(*str2 != '\0')
    {
        *ptr++ = *str2++;
    }
    *ptr = '\0';
    printf("concatenated string is %s\n", arr);
}

int strchr_impl(char *str, char c)
{
    int i = 0;
    int is_found = -1;
    while(*str != '\0')
    {
        if(*str == c)
        {
            is_found = i;
            break;
        }
        str++;
        i++;
    }
    return is_found;
}
int main(int argc, char *argv[])
{
    int len = strlen_impl("abc");
    printf("Length of abc is %d\n", len);
    len = strlen_impl("akshar");
    printf("Length of akshar is %d\n", len);
    len = strlen_impl("");
    printf("Length of is %d\n", len);

    strcat_impl("akshar", "raaj");

    int found = strchr_impl("akshar", 's');
    printf("Found at %d\n", found);
    found = strchr_impl("akshar", 'b');
    printf("Found at %d\n", found);

    return 0;
}
