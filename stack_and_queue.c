#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    struct Node *previous;
    struct Node *next;
    char *data;
}Node;

typedef struct
{
    Node *first;
    Node *last;
}List;

void die(char *message)
{
    printf("%s\n", message);
    exit(1);
}

List *List_create()
{
    List *list = malloc(sizeof(List));
    return list;
}

void List_print(List *list)
{
    Node *current = list->first;
    while(current!=NULL)
    {
        printf("%s\n", current->data);
        current = current->next;
    }
}

Node *List_get_last_node(List *list)
{
    //We will make sure that we send it a list with at least 1 Node.
    return list->last;
}

void List_push(List *list, Node *node)
{
    if(list->first==NULL)
    {
        list->first = node;
        list->last = node;
        return;
    }
    Node *last = list->last;
    last->next = node;
    node->previous = last;
    list->last = node;
}

int List_check_empty(List *list)
{
    if(list->first==NULL && list->last==NULL)
    {
        return 1;
    }
    return 0;
}

char *stack_pop(List *list)
{
    if(List_check_empty(list)==1)
    {
        return NULL;
    }
    Node *last = list->last;
    Node *previous = last->previous;
    list->last = previous;
    if(previous==NULL)
    {
        //If only one element was there in the list.
        //Then previous will be null.
        list->first = NULL;
    }
    char *another = strdup(last->data);
    free(last->data);
    free(last);
    return another;
}

Node *Node_create(char *data)
{
    char *another = strdup(data);
    if(another==NULL)
    {
        die("Could not copy string");
    }
    Node *node = malloc(sizeof(Node));
    if(node==NULL)
    {
        die("Could not allocate memory for Node");
    }
    node->data = another;
    return node;
}

void push(List *list, char *data)
{
    Node *node = Node_create(data);
    List_push(list, node);
}

void print_popped(char *item, char *ds)
{
    if(item==NULL)
    {
        printf("%s seems to be empty as no item was popped.\n", ds);
        return;
    }
    printf("Popped item from %s is %s.\n", ds, item);
}

int main(int argc, char *argv[])
{
    //Stack use follows
    List *stack = List_create();

    push(stack, "akshar");
    push(stack, "shabda");

    List_print(stack);

    char *popped;

    popped = stack_pop(stack);
    print_popped(popped, "Stack");
    popped = stack_pop(stack);
    print_popped(popped, "Stack");
    popped = stack_pop(stack);
    print_popped(popped, "Stack");

    push(stack, "shloka");
    popped = stack_pop(stack);
    print_popped(popped, "Stack");
    //Done with stack

    return 0;
}
