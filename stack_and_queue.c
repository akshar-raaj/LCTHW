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

char *stack_pop(List *list)
{
    Node *node = list->last;
    if(node==NULL)
    {
        //Its an empty list. So no manipulation required on list.
        return node;
    }
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

int main(int argc, char *argv[])
{
    List *list = List_create();
    push(list, "akshar");
    push(list, "shabda");
    List_print(list);
    return 0;
}
