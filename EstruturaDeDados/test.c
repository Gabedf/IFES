#include <stdio.h>
#include <stdlib.h>

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

List *create_list() 
{
    List *list = (List*)(malloc(sizeof(List)));
    if (list == NULL) 
    {
        printf("Não possível alocar memória."); 
        return 0;
    }
    return list;
}

void insert_list(List *l, int value)
{
    Node *new = (Node*)(malloc(sizeof(Node)));
    new->value = value;
    new->next = l->first;
    l->first = new;
}

void print_list(List *l) 
{
    Node *p = l->first;
    while (p != NULL) 
    {
        printf("%d ", p->value);
        p = p->next;
    } printf("\n");
}

int list_size(List *l)
{
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
        if (p->value == value) {return 1;}
        p = p->next;
    }
    return 0;
}

int isEmpity(List *l)
{
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
            if (prev == NULL) {l->first = p->next;}
            else {prev->next = p->next;}
            free(p);
            return 1;
        }
        else 
        {
            prev = p;
            p = p->next;
        }}
    return 0;
}

List *ll_concatenated(List *l1, List *l2) {
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

void remove_all_values(List *l, int value) 
{
    while (remove_value(l, value)) {remove_value(l, value);}
}

int main() {
    int size = 0, here, remove, response, v, element;
    List *l = create_list();
    List *l2 = create_list();

    // Add element to the first list
    printf("Add an element (l1): ");
    scanf("%d", &element);
    insert_list(l, element);
    printf("Do you want to add an element to the list?\n0 - No\n1 - Yes\nResponse: ");
    scanf("%d", &response);
    while (response) 
    {
        printf("Add an element: ");
        scanf("%d", &element);
        insert_list(l, element);
        printf("Do you want to add an element to the list 1?\n0 - No\n1 - Yes\nResponse: ");
        scanf("%d", &response);
    }

    // Add element to the second list 
    printf("Add an element (l2): ");
    scanf("%d", &element);
    insert_list(l2, element);
    printf("Do you want to add an element to the list 2?\n0 - No\n1 - Yes\nResponse: ");
    scanf("%d", &response);
    while (response) 
    {
        printf("Add an element: ");
        scanf("%d", &element);
        insert_list(l2, element);
        printf("Do you want to add an element to the list?\n0 - No\n1 - Yes\nResponse: ");
        scanf("%d", &response);
    }

    // Concatenating
    List *l3 = ll_concatenated(l, l2);
    print_list(l);
    print_list(l2);
    print_list(l3);
    return 0;
}