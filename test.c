#include <stdio.h>
#include <stdlib.h>
#include "function1.h"
#include <stdint.h>

#define BUFFER_LENGTH 100

typedef void (*increase)(int number);

void increase_1(int number)
{
    printf("Number is %d\n", (number+1));
}

void increase_2(int number)
{
    printf("Number is %d\n", (number+2));
}

void use_increase(int number, increase fun)
{
    fun(number);
}

typedef struct{
    char *lane;
}Address;

typedef struct{
    Address *address;
    int age;
}Person;

Address *Address_create(char *lane)
{
    Address *address = malloc(sizeof(Address));
    address->lane = lane;
    return address;
}

void Address_print(Address *address)
{
    printf("Address is %s\n", address->lane);
}

Person *Person_create(Address *address, int age)
{
    Person *person = malloc(sizeof(Person));
    person->address = address;
    person->age = age;
    return person;
}

void Person_print(Person *person)
{
    printf("Person is %d.\n", person->age);
    printf("Lives at %s\n", person->address->lane);
}

int main(int argc, char *argv[])
{
    int num;
    num = 100;
    printf("Number is %d\n", num);

    char ch;
    ch = 'a';
    printf("Character is %c\n", ch);

    int num_arr[10];
    int i;
    for(i=0; i<10; i++)
    {
        printf("Arr %d is %d\n", i, num_arr[i]);
    }

    num_arr[3] = 10;
    for(i=0; i<10; i++)
    {
        printf("Arr %d is %d\n", i, num_arr[i]);
    }

    num_arr[3] = 15;
    for(i=0; i<10; i++)
    {
        printf("Arr %d is %d\n", i, num_arr[i]);
    }
    return 0;
i
