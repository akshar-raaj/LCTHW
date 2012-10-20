#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Person
{
    int age;
    char *name;
};

struct Person *Person_create(int age, char *name)
{
    struct Person *person = malloc(sizeof(struct Person));
    assert(person!=NULL);
    person->age = age;
    person->name = name;
    return person;
}

struct Person *Person_create_empty()
{
    struct Person *person = malloc(sizeof(struct Person));
    assert(person!=NULL);
    return person;
}

void Person_print(struct Person *person)
{
    printf("Name is %s\n", person->name);
    printf("Age is %d\n", person->age);
}

void die(char *message)
{
    printf("%s", message);
    exit(1);
}

int main(int argc, char *argv[])
{
    if (argc<2)
    {
        die("Usage: ./file_io <file_name>\n");
    }

    char *filename = argv[1];
    FILE *fp;
    char *mode = "w";
    fp = fopen(filename, mode);
    assert(fp!=NULL);

    //fprintf(fp, "Testing....\n");
    struct Person *person = Person_create(11, "test");

    int ret = fwrite(person, sizeof(struct Person), 1, fp);
    if(ret != 1)
    {
        die("Could not write struct to file\n");
    }

    free(person);

    int closed = fclose(fp);
    if(closed != 0)
    {
        die("File could not be closed properly");
    }

    fp = fopen(filename, "r+");
    assert(fp!=NULL);
    person = Person_create_empty();
    ret = fread(person, sizeof(struct Person), 1, fp);
    if(ret != 1)
    {
        die("Could not read from the file\n");
    }

    Person_print(person);
    return 0;
}
