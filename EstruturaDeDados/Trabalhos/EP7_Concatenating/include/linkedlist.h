#ifndef LINKEDLIST
#define LINKEDLIST

typedef struct list LinkedList;
typedef struct node Node;

// Create a new linked list    
LinkedList *create_list();

// Insert a new element at the beginning of the list
void insert_list(LinkedList *l, int i);

// Insert many elements untill the command to stop
void insert_elements(LinkedList *l);

// Print one by one the values of the list
void print_list(LinkedList *l);

// Return the size of a list
int list_size(LinkedList *l);

// Verify is a value is on the list
int verify_value(LinkedList *l, int value);

// Verify is the list is empity
int isEmpity(LinkedList *l);

// Remove a value of the list
int remove_value(LinkedList *l, int value);

// Remove every value of the list
void remove_all_values(LinkedList *l, int values);

// Concatenate two linkedLists
LinkedList *ll_concatenated(LinkedList *l1, LinkedList *l2);

#endif