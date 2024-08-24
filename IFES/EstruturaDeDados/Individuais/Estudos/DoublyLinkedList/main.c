#include <stdio.h>
#include <stdlib.h>
#include "list.c"

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
