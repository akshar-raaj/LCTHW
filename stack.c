#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    char *values[20];
    int num_elements;
};

struct Stack *Stack_create()
{
    struct Stack *stack = malloc(sizeof(struct Stack));
    stack->num_elements = 0;
    return stack;
}

void Stack_push(struct Stack *stack, char *element)
{
    int num_elements = stack->num_elements;
    if(num_elements==20)
    {
        printf("Aborting...Stack Overflow");
        exit(1);
    }
    stack->values[num_elements] = element;
    printf("Pushed %s\n", stack->values[num_elements]);
    stack->num_elements = num_elements+1;
}

void Stack_pop(struct Stack *stack)
{
    int num_elements = stack->num_elements;
    num_elements = num_elements-1;
    if(num_elements==-1)
    {
        printf("Aborting...Stack Underflow\n");
        exit(1);
    }
    printf("Value is %s\n", stack->values[num_elements]);
    stack->num_elements = num_elements;
}

int main(int argc, char *argv[])
{
    struct Stack *stack = Stack_create();
    Stack_push(stack, "akshar");
    Stack_push(stack, "abc");
    Stack_push(stack, "shabda");
    Stack_push(stack, "sudoku");

    Stack_pop(stack);
    Stack_pop(stack);
    Stack_pop(stack);

    Stack_push(stack, "shloka");
    Stack_push(stack, "somesome");

    Stack_pop(stack);
    Stack_pop(stack);
    Stack_pop(stack);

    //Aborting. stack overflow
    Stack_pop(stack);
    return 0;
}
