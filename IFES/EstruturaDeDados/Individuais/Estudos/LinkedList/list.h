#ifndef LIST
#define LIST

typedef struct list List;
typedef struct node Node;

// Create a new linked list    
List *create_list();

// Insert a new element at the beginning of the list
void insert_list(List *l, int i);

// Insert many elements untill the command to stop
void insert_elements(List *l);

// Print one by one the values of the list
void print_list(List *l);

// Return the size of a list
int list_size(List *l);

// Verify is a value is on the list
int verify_value(List *l, int value);

// Verify is the list is empity
int isEmpity(List *l);

// Remove a value of the list
int remove_value(List *l, int value);

// Remove every value of the list
void remove_all_values(List *l, int values);

#endif