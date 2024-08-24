#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct doublylist 
{
    Node *first;
    Node *last;
    int counter;
};
 
struct node
{
    int value;
    Node *next;
    Node *prev;
};

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
    new->next = list->first;
    new->prev = NULL;

    if (isEmpity(list)) {list->first->prev = new;}
    else {list->last = new;}

   list->first = new; 
   list->counter++;      
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

int list_size(DoublyList *list) {return list->counter}

void remove_all_values(DoublyList *list, int value)
{
    while (remove_value(list, value)) {remove_value(list, value)}
}

int main() 
{
    int size = 0, here, remove, response, v;
    DoublyList *l = create_List();
    insert_elements(l);
    print_list(l);

    // Check if value exists in list
    printf("Do you want to check if a value exists in the list?\n0 - No\n1 - Yes\nResponse: ");
    scanf("%d", &response);
    if (response) 
    {
        printf("Enter the value you want to check: ");
        scanf("%d", &v);
        here = verify_value(l, v);
        if (here) {printf("Value found.\n");}
        else {printf("Value not found.\n");}
    }

    // Remove value from list
    printf("Do you want to remove a value from the list?\n0 - No\n1 - Yes\n2 - Yes, remove all occurrences\nResponse: ");
    scanf("%d", &response);
    if (response) 
    {
        printf("Enter the value you want to remove: ");
        scanf("%d", &remove);
        if (response == 1) {remove_value(l, remove);}
        else {remove_all_values(l, remove);}
    }
    print_list(l);
    size = list_size(l);
    printf("The size of the list is: %d\n", size);

    return 0;
}
