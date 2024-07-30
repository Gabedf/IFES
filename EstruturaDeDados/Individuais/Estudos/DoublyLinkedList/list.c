#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct doublylist 
{
    Node *first;
    Node *last;
    int counter;
}
 
struct node
{
    int value;
    Node *next;
    Node *prev;
}

DoublyList *create_list() 
{
    DoublyList *list = (DoublyList*)(malloc(sizeof(DoublyList)));
    if (list == NULL) {
        printf("Não possível alocar memória.");
        return 0;}

    list->first = NULL;
    list->last = NULL;
    list->counter = 0;
    return list;
}

int list_size(DoublyList *list) 
{
    return list->counter;
}

int isEmpity(DoublyList *list)
{
    if (list->counter == 0) {return 1;}
    return 0;
}

void insert_list(DoublyList *list, int value)
{
    Node *new = (Node*)(malloc(sizeof(Node)));
    new->value = value;
    new->new = list->first;
    new->prev = NULL;

    if (isEmpity(list)) {list->first->prev = new;}
    else {l->last = new;}

   l->first = new; 
   l->counter++;      
}

void print_list(DoublyList *list)
{
    for (Node *p = list->first; p->next != NULL; p = p->next) 
    {
        printf("%d ", p->value);
    }
}

int verify_value(DoublyList *list, int value)
{
    for (Node *p = list->first; p->next != NULL; p = p->next)
    {
        if (p->value == value) {return 1;} 
    }
    return 0;
}

int remove_value(DoublyList *list, int value)
{  
    Node *p = list->first;
    while (p != NULL) 
    {
        if (p->value == value) 
        {
            if (p->prev == NULL) {list->first = p->next;}
            else {p->prev->next = p->next;}

            if (p->value == list->last) {list->last = p->prev;}
            else {p->next->prev = p->prev;}

            free(p);
            list->counter--;
            return 1;
        }
        p = p->next;
    }
    return 0;
}