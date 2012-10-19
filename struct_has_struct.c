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
    return 0;
}
