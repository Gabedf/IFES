#include <stdio.h>
#include <stdlib.h>

// For now, just to make my life easier, i'm putting all functions here and will change it ASAP
typedef struct list List;   
typedef struct start Start;   
struct start 
{
    struct List *first;
};

struct list 
{
    int value;      
    struct list *next; 
};


Start *create_List() 
{
    Start *l = (Start*)(malloc(sizeof(Start)));
    l->first = NULL;
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

int main() 
{
    List *l = create_List();
    l = insert_elements(l);
    print_list(l);

    int size = 0, here, remove;
    here = verify_value(l, 88);
    size = list_size(l);
    printf("Tamanho da lista: %d\nValor está na lista? %d\n", size, here);

    printf("Digite o valor da lista a remover: ");
    scanf("%d", &remove);
    here = remove_value(l, remove);
    print_list(l);
    return 0;
     
}