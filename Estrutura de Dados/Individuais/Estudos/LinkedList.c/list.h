#ifndef LIST
#define LIST

typedef struct list List;   
typedef struct start Start;   

// Create a new linked list    
List *create_list();

// Insert a new element at the beginning of the list
List *insert_list(List *l, int i);

// Insert many elements untill the command to stop
List *insert_elements(List *l);

// Print one by one the values of the list
void print_list(List *l);

// Return the size of a list
int list_size(List *l) 

// Verify is a value is on the list
int verify_value(List *l, int value);

// Verify is the list is empity
int isEmpity(List *l)

#endif