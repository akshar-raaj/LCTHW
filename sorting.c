#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    struct Node *previous;
    struct Node *next;
    int data;
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
    list->first = NULL;
    list->last = NULL;
    return list;
}

void List_print(List *list)
{
    Node *current = list->first;
    while(current!=NULL)
    {
        printf("%d\n", current->data);
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

Node *Node_create(int data)
{
    Node *node = malloc(sizeof(Node));
    if(node==NULL)
    {
        die("Could not allocate memory for Node");
    }
    node->data = data;
    return node;
}

void push(List *list, int data)
{
    Node *node = Node_create(data);
    List_push(list, node);
}

int List_Node_count(List *list)
{
    int i = 0;
    Node *current = list->first;
    while(current!=NULL)
    {
        i++;
        current  = current->next;
    }
    return i;
}

void bubble_sort(List *list)
{
    int count = List_Node_count(list);
    printf("Number of elements in list is %d\n", count);

    List_print(list);
    int i;
    Node *current;
    Node *after_current;
    for(i=1; i<count; i++)
    {
        current = list->first;
        while(current->next!=NULL)
        {
            after_current = current->next; 
            //compare the adjacent entries of list
            if(current->data>after_current->data)
            {
                current->next = after_current->next;
                if(after_current->next!=NULL)
                {
                    Node *ab = after_current->next;
                    ab->previous = current;
                }
                if(current->previous!=NULL)
                {
                    Node *cd = current->previous;
                    cd->next = after_current;
                }
                after_current->previous = current->previous;
                current->previous = after_current;
                after_current->next = current;

                if(current==list->first)
                {
                    list->first = after_current;
                }
            }
            else{
                current = after_current;
            }
        }
    }

    printf("List after bubble sort\n");
    List_print(list);
}

List *concatenate(List *lesser, Node *pivot, List *greater)
{
    Node *lesser_last = lesser->last;
    //Appending lesser's last to pivot
    if(lesser_last==NULL)
    {
        lesser->first = pivot;
        lesser->last = pivot;
    }
    else
    {
        lesser_last->next = pivot;
        lesser->last = pivot;
        pivot->previous = lesser_last;
    }

    //lesser and last are already joined here.
    //Need to join greater to them
    lesser_last = lesser->last;
    Node *greater_first = greater->first;
    if(greater_first==NULL)
    {

    }
    else
    {
        lesser_last->next = greater_first;
        greater_first->previous = lesser_last;
        lesser->last = greater->last;
    }
    return lesser;
}


List *quick_sort(List *list)
{
    int count = List_Node_count(list);
    if(count==1 || count==0)
    {
        return list;
    }
    List *lesser = List_create();
    List *greater = List_create();
    Node *pivot = list->first;
    Node *current = pivot->next;
    Node *to_push;
    while(current!=NULL)
    {
        to_push = current;
        current = current->next;
        to_push->previous = NULL;
        to_push->next = NULL;
        if(to_push->data<pivot->data)
        {
            List_push(lesser, to_push);
        }
        else
        {
            List_push(greater, to_push);
        }
    }
    pivot->next = NULL;
    pivot->previous = NULL;
    return concatenate(quick_sort(lesser), pivot, quick_sort(greater));
}

int main(int argc, char *argv[])
{
    /*List *list = List_create();
    push(list, 5);
    push(list, 1);
    push(list, 1);
    push(list, 2);
    push(list, 0);

    bubble_sort(list);*/

    List *list = List_create();
    push(list, 2);
    push(list, 1);
    push(list, 5);
    push(list, 0);
    push(list, 1);
    push(list, 99);
    push(list, -7);
    printf("Unsorted list\n");
    List_print(list);

    printf("Sorted list\n");
    List *sorted = quick_sort(list);
    List_print(sorted);

    quick_sort(list);
    return 0;
}
