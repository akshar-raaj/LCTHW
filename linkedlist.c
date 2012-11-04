#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char *data;
    struct Item *next;
}Item;

typedef struct{
    Item *first;
}LinkedList;

void die(char *message)
{
    printf("%s\n", message);
    exit(1);
}

LinkedList *LinkedList_create()
{
    LinkedList *list = malloc(sizeof(LinkedList));
    if(list==NULL)
    {
        die("Could not allocate memory for LinkedList");
    }
    return list;
}

Item *Item_create(char *data)
{
    char *another = strdup(data);
    if(another==NULL)
    {
        die("Could not duplicate string.");
    }
    Item *item = malloc(sizeof(Item));
    if(item==NULL)
    {
        die("Could not allocate memory for Item");
    }
    item->data = another;
    return item;
}

void append(LinkedList *list, Item *item)
{
    Item *first = list->first;        
    if(first==NULL)
    {
        list->first = item;
        return;
    }

    Item *last_item = first;
    while(last_item->next!=NULL)
    {
        last_item = last_item->next;
    }
    last_item->next = item;
}

char *pop(LinkedList *list)
{
    char *data;
    Item *first = list->first;

    if(first==NULL)
    {
        printf("List is empty\n");
        return NULL;
    }

    if(first->next==NULL)
    {
        data = first->data;
        free(first);
        list->first = NULL;
        return data;
    }

    Item *last_item;
    Item *second_last;
    second_last = first;
    last_item = first->next;
    while(last_item->next!=NULL)
    {
        second_last = last_item;
        last_item = last_item->next;
    }
    data = last_item->data;
    free(last_item);
    second_last->next = NULL;
    return data;
}

void LinkedList_print(LinkedList *list)
{
    if(list==NULL)
    {
        printf("You provided an invalid list\n");
        return;
    }
    Item *first = list->first;
    if(first==NULL)
    {
        printf("Empty list\n");
        return;
    }

    Item *last_item = first;
    while(last_item->next!=NULL)
    {
        printf("%s\n", last_item->data);
        last_item = last_item->next;
    }
    printf("%s\n", last_item->data);
}

void print_popped(char *popped)
{
    if(popped==NULL)
    {
        return;
    }
    printf("Popped element is %s\n", popped);
}

int main(int argc, char *argv[])
{
    LinkedList *list = LinkedList_create();

    Item *item;
    char *popped;

    popped = pop(list);
    print_popped(popped);

    item = Item_create("akshar");
    append(list, item);

    item = Item_create("shabda");
    append(list, item);

    item = Item_create("shloka");
    append(list, item);

    popped = pop(list);
    print_popped(popped);

    printf("Printing list.............................\n");
    LinkedList_print(list);

    popped = pop(list);
    print_popped(popped);

    printf("Printing list.............................\n");
    LinkedList_print(list);

    popped = pop(list);
    print_popped(popped);

    printf("Printing list.............................\n");
    LinkedList_print(list);
    return 0;
}
