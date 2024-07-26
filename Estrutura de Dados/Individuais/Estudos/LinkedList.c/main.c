#include <stdio.h>
#include <stdlib.h>

// For now, just to make my life easier, I'm putting all functions here and will change it ASAP

typedef struct list List;
typedef struct node Node;

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
    l->first = NULL;
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

int isEmpty(List *l) {
    if (l->first == NULL) {return 1;}
    return 0;
}

int remove_value(List *l, int value)
{
    Node *p = l->first;
    Node *prev = NULL;

    while (p != NULL)
    {
        if (p->value == value)
        {
            // For the case of the value being in the first node of the list
            if (prev == NULL)
                l->first = p->next;
            else
                prev->next = p->next;
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

void remove_all_values(List *l, int value)
{
    while (remove_value(l, value)) { /* Remove all occurrences */ }
}

int main() 
{
    int size = 0, here, remove, response, v;
    List *l = create_List();
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
