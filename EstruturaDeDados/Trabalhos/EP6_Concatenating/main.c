#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"  

int main() {
    List *l1 = create_list();
    List *l2 = create_list();

    // Add element to the first list
    insert_list(l1, 12);
    insert_list(l1, 23);
    insert_list(l1, 24);
    insert_list(l1, 65);
    insert_list(l1, 21);
    insert_list(l1, 64);

    // Add element to the second list 
    insert_list(l2, 3);
    insert_list(l2, 4);
    insert_list(l2, 5);
    insert_list(l2, 42);

    // Concatenating
    List *l3 = ll_concatenated(l, l2);
    printf("L1: ");
    print_list(l);
    printf("L2: ");
    print_list(l2);
    printf("L3: ");
    print_list(l3);
    
    return 0;
}