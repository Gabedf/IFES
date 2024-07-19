#include <stdio.h>
#include <stdlib.h>

// For now, just to make my life easier, i'm putting all functions here and will change it ASAP

struct node
{
    int value;      
    struct node *next;
};
    typedef struct node List;  

List *create_List() {
        List *l = (List*)(malloc(sizeof(List)));
        l->next = NULL;
        return l;}

List *insert_list(List *l, int i) {
        List *new = (List*)(malloc(sizeof(List)));
        new->value = i;
        new->next = l;
        return new;}

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

int main() 
{
    List *l = create_List();
    l = insert_elements(l);
    print_list(l);

    return 0;
     
}