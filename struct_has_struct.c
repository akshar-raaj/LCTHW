#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Person
{
    int age;
};

struct Employee
{
    struct Person *person;
    int salary;
};

struct Person *Person_create(int age)
{
    struct Person *person = malloc(sizeof(struct Person));
    assert(person!=NULL);
    person->age = age;
    return person;
}

void Person_print(struct Person *person)
{
    printf("Age is %d\n", person->age);
}

struct Employee *Employee_create(struct Person *person, int salary)
{
    struct Employee *employee = malloc(sizeof(struct Employee));
    assert(employee!=NULL);
    employee->person = person;
    employee->salary = salary;

    return employee;
}

void Employee_print(struct Employee *employee)
{
    printf("Age is %d\n", employee->person->age);
    printf("Salary is %d\n", employee->salary);
}

int main(int argc, char *argv[])
{
    struct Person *person = Person_create(22);
    Person_print(person);

    struct Employee *employee = Employee_create(person, 20000);
    Employee_print(employee);

    struct Person person_array[2];
    struct Person *p1 = Person_create(12);
    struct Person *p2 = Person_create(14);
    person_array[0] = *p1;
    person_array[1] = *p2;

    struct Person pp;
    int i;
    for(i=0; i<2; i++)
    {
        pp = person_array[i]; 
        printf("Person's age is %d\n", pp.age);
    }

    struct Person *person_pointer_array[2];
    person_pointer_array[0] = p1;
    person_pointer_array[1] = p2;

    printf("Using an array of pointers\n");
    for(i=0; i<2; i++)
    {
        printf("Person'age is %d\n", person_pointer_array[i]->age);
    }

    return 0;
}
