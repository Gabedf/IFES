#ifndef LIST
#define LIST

typedef struct node List;   

// Create a new linked list    
List *create_list();

// Insert a new element at the beginning of the list
List *insert_list(List *l, int i);

// Insert many elements untill the command to stop
List *insert_elements(List *l);

// Print one by one the values of the list
void print_list(List *l);

#endif