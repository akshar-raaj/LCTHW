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

void LinkedList_append(LinkedList *list, Item *item)
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

char *LinkedList_pop(LinkedList *list)
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

int LinkedList_count(LinkedList *list)
{
    Item *first = list->first;
    int count = 0;
    if(first==NULL)
    {
        return count;
    }
    count = 1;
    Item *last = first;
    while(last->next!=NULL)
    {
        count++; 
        last = last->next;
    }
    return count;
}

int count(LinkedList *list, char *data){
    Item *current = list->first;
    char *item_data;
    int eq;
    int count = 0;
    if(current==NULL)
    {
        return count;
    }
    while(current->next!=NULL)
    {
        item_data = current->data; 
        eq = strcmp(data, item_data);
        if(eq==0)
        {
            count++;
        }
        current = current->next;
    }
    if(strcmp(data, current->data)==0)
    {
        count++;
    }
    return count;
}

void LinkedList_insert(LinkedList *list, int index, Item *item)
{
    if(list==NULL)
    {
        die("List doesn't exist.");
    }

    int i = 0;
    if(index<0)
    {
        printf("You must provide non-negative index\n");
        return;
    }

    int count = LinkedList_count(list);
    if(index>=count)
    {
        LinkedList_append(list, item);
        return;
    }

    if(index==0)
    {
        Item *first = list->first;
        list->first = item;
        item->next = first;
        return;
    }

    Item *before = list->first;
    Item *after = before->next;
    for(i=0; i<index-1; i++)
    {
        before = after;
        after = after->next;
    }
    before->next = item;
    item->next = after;
}

void LinkedList_extend(LinkedList *list1, LinkedList *list2)
{
    Item *current = list1->first;
    if(current==NULL)
    {
        list1->first = list2->first;
    }
    else
    {
        while(current->next!=NULL)
        {
            current = current->next;
        }
        Item *list2_first = list2->first;
        current->next = list2_first;
    }
}

int LinkedList_index(LinkedList *list, char *data)
{
    int index = -1;
    Item *first = list->first;
    if(first==NULL)
    {
        return index; 
    }
    while(first->next!=NULL)
    {
        index++;
        if(strcmp(first->data, data)==0)
        {
            return index;
        }
        first = first->next;
    }
    index++;
    if(strcmp(first->data, data)==0)
    {
        return index;
    }
    return -1;
}

int LinkedList_remove(LinkedList *list, char *data)
{
    Item *first = list->first;
    Item *to_remove;
    Item *previous;
    int removed = -1;
    if(first==NULL)
    {
        printf("%s not in list.\n", data);
        return removed;
    }
    to_remove = first;

    //If removing the first element
    if(strcmp(to_remove->data, data)==0)
    {
        removed = 1;
        list->first = to_remove->next;
        free(to_remove);
        return removed;
    }
    previous = to_remove;
    to_remove = to_remove->next;
    while(to_remove!=NULL)
    {
        removed++;
        if(strcmp(to_remove->data, data)==0)
        {
            previous->next = to_remove->next;
            free(to_remove);
            return removed;
        }
        previous = to_remove;
        to_remove = to_remove->next;
    }
    return -1;
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

void append(LinkedList *list, char *data)
{
    char *duplicate = strdup(data);
    Item *item = Item_create(duplicate);
    LinkedList_append(list, item);
}

void insert(LinkedList *list, int index, char *data)
{
    char *duplicate = strdup(data);
    Item *item = Item_create(duplicate);
    LinkedList_insert(list, index, item);
}

void extend(LinkedList *list1, LinkedList *list2)
{
    LinkedList_extend(list1, list2);
}

int index_of(LinkedList *list, char *data)
{
    int index = LinkedList_index(list, data);
    return index;
}

int remove_it(LinkedList *list, char *data)
{
    int removed = LinkedList_remove(list, data);
    return removed;
}

int main(int argc, char *argv[])
{
    LinkedList *list = LinkedList_create();

    //This will insert item at position 0
    insert(list, 5, "akshar");
    //List is ["akshar"]

    append(list, "shabda");
    //List is ["akshar", "shabda"]

    append(list, "shloka");
    //List is ["akshar", "shabda", "shloka"]

    insert(list, 0, "theju");
    //List is ["theju", "akshar", "shabda", "shloka"]

    insert(list, 2, "jakh");
    //List is ["theju", "akshar", "jakh", "shabda", "shloka"]

    insert(list, 110, "foo");
    //List is ["theju", "akshar", "jakh", "shabda", "shloka", "foo"]

    append(list, "bar");
    //List is ["theju", "akshar", "jakh", "shabda", "shloka", "foo", "bar"]

    insert(list, 110, "foo");
    //List is ["theju", "akshar", "jakh", "shabda", "shloka", "foo", "bar", "foo"]

    //printf("Printing list.............................\n");
    //LinkedList_print(list);

    printf("akshar occurs %d times.\n", count(list, "akshar"));
    printf("foo occurs %d times.\n", count(list, "foo"));
    printf("abc occurs %d times.\n", count(list, "abc"));

    LinkedList *list1 = LinkedList_create();

    LinkedList *list2 = LinkedList_create();
    append(list2, "nguyen");
    append(list2, "hai");

    extend(list, list2);

    printf("Printing list.............................\n");
    LinkedList_print(list);

    printf("Index of akshar is %d\n", index_of(list, "akshar"));
    printf("Index of abcd is %d\n", index_of(list, "abcd"));
    printf("Index of hai is %d\n", index_of(list, "hai"));

    remove_it(list, "theju");
    printf("Printing list.............................\n");
    LinkedList_print(list);

    //Remove from middle of list
    remove_it(list, "jakh");
    printf("Printing list.............................\n");
    LinkedList_print(list);

    //Try removing non-existing entry
    remove_it(list, "abcd");
    printf("Printing list.............................\n");
    LinkedList_print(list);

    //Remove from end of list
    remove_it(list, "hai");
    printf("Printing list.............................\n");
    LinkedList_print(list);
    return 0;
}
