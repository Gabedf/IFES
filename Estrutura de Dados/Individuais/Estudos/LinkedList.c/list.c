
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct node 
{
    int value;      
    struct node *next; 
};

List *create_List() 
{
    List *l = (List*)(malloc(sizeof(List)));
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
    printf("Do you wanna add an element?\n\n1 - Yes\n2 - No\n\n");
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