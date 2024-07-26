
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct start 
{
    struct List *first;
};

struct list 
{
    int value;      
    struct list *next; 
};

List *create_List() 
{
    Start *l = (Start*)(malloc(sizeof(Start)));
    l->next = NULL;
    return l;
}

List *insert_list(List *l, int i) 
{
    List *new = (List*)(malloc(sizeof(List)));
    new->value = i;
    new->next = l;
    return new;
}

List *insert_elements(List *l) 
{
    int answer, value;
    printf("Do you wanna add an element?\n\n1 - Yes\n0 - No\n\n");
    scanf("%d", &answer);

    while (answer) 
    {
        printf("Enter a value to add: ");
        scanf("%d", &value);
        l = insert_list(l, value);
        printf("Do you wanna add an element?\n\n1 - Yes\n2 - No\n\n");
        scanf("%d", &answer);
    }

    return l;
}

void print_list(List *l) 
{
    List *current = l;
    while (current->next != NULL) 
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

int list_size(List *l) {
    int size = 0;
    List *current = l;
    while (current->next != NULL) 
    {
        size++;
        current = current->next;
    }
    return size;
}

int verify_value(List *l, int value) {
    while (l->next != NULL) {
        if (l->value == value) {return 1;}
        l = l->next;
    }
    return 0;
}

int isEmpity(List *l) {
    if (l->first == NULL) {return 0;}
    return 1;
}

int remove_value(List *l, int value) {
    List *x = l->next;
    List *prev = NULL;

    while (x != NULL) 
    {
        if (x->value == value) 
        {
            if (prev == NULL) {l = x->next;}
            else {prev->first = x->next;}
            free(x);
            return 1;
        }
        else 
        {
            prev = x;
            x = x->next;
        }
    }
    return 0;
}