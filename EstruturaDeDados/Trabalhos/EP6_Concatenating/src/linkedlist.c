#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

struct list 
{
    Node *first;
};

struct node 
{
    int value;
    Node *next;
};

LinkedList *create_List() 
{
    LinkedList *l = (LinkedList*)(malloc(sizeof(LinkedList)));
    l->next = NULL;
    return l;
}

void insert_list(LinkedList *l, int i) 
{
    Node *new = (Node*)(malloc(sizeof(Node)));
    new->value = i;
    new->next = l->first;
    l->first = new;
}

void insert_elements(LinkedList *l) 
{
    int answer, value;
    printf("Do you want to add an element?\n\n1 - Yes\n0 - No\n\n");
    scanf("%d", &answer);

    while (answer) 
    {
        printf("Enter a value to add: ");
        scanf("%d", &value);
        insert_list(l, value);
        printf("Do you want to add another element?\n\n1 - Yes\n0 - No\n\n");
        scanf("%d", &answer);
    }
}

void print_list(LinkedList *l) 
{
    for (Node *p = l->first; p != NULL; p = p->next) 
    {
        printf("%d ", p->value);
    }
    printf("\n");
}

int list_size(LinkedList *l) {
    int size = 0;
    Node *p = l->first;
    while (p != NULL)
    {
        size++;
        p = p->next;
    }
    return size;
}

int verify_value(LinkedList *l, int value)
{
    Node *p = l->first;
    while (p != NULL)
    {
        if (p->value == value)
            return 1;
        p = p->next;
    }
    return 0;
}

int isEmpity(LinkedList *l) {
    if (l->first == NULL) {return 0;}
    return 1;
}

int remove_value(LinkedList *l, int value)
{
    Node *p = l->first;
    Node *prev = NULL;
    while (p != NULL)
    {
        if (p->value == value)
        {
            if (prev == NULL) {l->first = p->next;} 
            else {prev->next = p->next;}
            free(p);
            return 1;
        }
        else
        {
            prev = p;
            p = p->next;
        }
    }
    return 0;
}

void remove_all_values(LinkedList *l, int values)
{
    while (remove_value(l, v)) {remove_value(l, v)};
}

LinkedList *ll_concatenated(List *l1, List *l2) {
    List *l3 = create_list();
    Node *p = l1->first;
    while (p != NULL) 
        {
        insert_list(l3, p->value);
        p = p->next;
        if (p == NULL) 
        {
            p = l2->first;
            while (p != NULL) 
            {
                insert_list(l3, p->value);
                p = p->next;
            }
        }}
    return l3;
}