#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person{
    char *name;
    int age;
    int height;
    int weight;
};

struct Person *Person_create(char *name, int age, int height, int weight)
{
    struct Person *who = malloc(sizeof(struct Person));
    assert(who!=NULL);

    who->name = strdup(name);
    who->age = age;
    who->height = height;
    who->weight = weight;
    return who;
}

void Person_print(struct Person *who)
{
    printf("Name is %s\n", who->name);
    printf("\tAge is %d\n", who->age);
    printf("\tHeight is %d\n", who->height);
    printf("\tWeight is %d\n", who->weight);
}

void Person_destroy(struct Person *who)
{
    assert(who!=NULL);
    free(who->name);
    free(who);
}

int main(int argc, char *argv[])
{
    struct Person *akshar = Person_create("Akshar Raaj", 22, 165, 55);

    printf("akshar is at memory location %p\n", akshar);

    Person_print(akshar);

    struct Person real_akshar = *akshar;
    printf("Name is %s\n", real_akshar.name);

    Person_destroy(akshar);
    return 0;
}
