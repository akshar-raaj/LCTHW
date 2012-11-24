#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int value;
    struct Node *next;
    struct List *list;
}Node;

typedef struct
{
    Node *first;
}List;

void die(char *message)
{
    printf("%s\n", message);
    exit(1);
}

Node *Node_create(int data)
{
    Node *node = malloc(sizeof(Node));
    if(node==NULL)
    {
        die("Could not allocate memory for Node");
    }
    node->value = data;
    node->list = NULL;
    node->next = NULL;
    return node;
}

List *List_create()
{
    List *list = malloc(sizeof(List));
    if(list==NULL)
    {
        die("Could not allocate memory for List");
    }
    list->first = NULL;
    return list;
}

Node *List_get_last_node(List *list)
{
    Node *current = list->first;
    if(current==NULL)
    {
        return current;
    }
    while(current->next!=NULL)
    {
        current = current->next;
    }
    return current;
}

void List_append(List *list, Node *node)
{
    Node *last = List_get_last_node(list);
    if(last==NULL)
    {
        list->first = node;
        return;
    }
    last->next = node;
}

//Just for testing
void List_print(List *list)
{
    Node *current = list->first;
    while(current!=NULL)
    {
        printf("%d\n", current->value);
        current = current->next;
    }
}

Node *Tree_add_root(int data)
{
    Node *node = Node_create(data);
    return node;
}

void Tree_add_child(Node *parent, Node *child)
{
    List *list = parent->list;
    if(list==NULL)
    {
        list = List_create();
        parent->list = list;
    }
    List_append(list, child);
}

void Tree_print(Node *node)
{
    //It will print the list in
    //pre-order traversal
    printf("%d\n", node->value);
    List *list = node->list;
    if(list==NULL)
    {
        //It is a leaf node
        return;
    }
    else
    {
        //Loop through the children
        //consideraing them as tree
        Node *current = list->first;
        while(current!=NULL)
        {
            Tree_print(current);
            current = current->next;
        }
    }
}

int Tree_search(Node *node, int value)
{
    //Search a given item in the
    //subtree starting from the node
    //provided as argument
    if(node->value==value)
    {
        return 1;
    }

    List *list = node->list;

    //Is it a leaf node?
    if(list==NULL)
    {
        return -1;
    }
    else
    {
        Node *current = list->first;
        while(current!=NULL)
        {
            int found = Tree_search(current, value);
            if (found==1)
            {
                return 1;
            }
            current = current->next;
        }
        return -1;
    }
}

int main(int argc, char *argv[])
{
    Node *node1 = Tree_add_root(1);
    
    Node *node11 = Node_create(11);
    Tree_add_child(node1, node11);

    Node *node111 = Node_create(111);
    Tree_add_child(node11, node111);

    Node *node12 = Node_create(12);
    Tree_add_child(node1, node12);

    Node *node13 = Node_create(13);
    Tree_add_child(node1, node13);

    Node *node131 = Node_create(131);
    Tree_add_child(node13, node131);

    /*printf("Print entire tree\n");
    Tree_print(node1);

    printf("Print a subtree\n");
    Tree_print(node13);*/

    int find = 131;
    int found = Tree_search(node1, find);
    if(found==1)
    {
        printf("%d found\n", find);
    }
    else
    {
        printf("%d not found\n", find);
    }

    find = 1311;
    found = Tree_search(node1, find);
    if(found==1)
    {
        printf("%d found\n", find);
    }
    else
    {
        printf("%d not found\n", find);
    }

    return 0;
}
