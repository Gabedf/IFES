#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct list 
{
    Node *first;
};

struct node 
{
    int value;
    Node *next;
};

List *create_List() 
{
    List *l = (List*)(malloc(sizeof(List)));
    l->next = NULL;
    return l;
}

void insert_list(List *l, int i) 
{
    Node *new = (Node*)(malloc(sizeof(Node)));
    new->value = i;
    new->next = l->first;
    l->first = new;
}

void insert_elements(List *l) 
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

void print_list(List *l) 
{
    for (Node *p = l->first; p != NULL; p = p->next) 
    {
        printf("%d ", p->value);
    }
    printf("\n");
}

int list_size(List *l) {
    int size = 0;
    Node *p = l->first;
    while (p != NULL)
    {
        size++;
        p = p->next;
    }
    return size;
}

int verify_value(List *l, int value)
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

int isEmpity(List *l) {
    if (l->first == NULL) {return 0;}
    return 1;
}

int remove_value(List *l, int value)
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

void remove_all_values(List *l, int values)
{
    while (remove_value(l, v)) {remove_value(l, v)};
}
