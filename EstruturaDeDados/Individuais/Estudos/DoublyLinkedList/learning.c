typedef struct list DoublyList;
typedef struct node Node;

struct list 
{
    Node *first;
    Node *last;
    int counter;
};

struct node 
{
    int v;
    Node *next;
    Node *prev;
};

DoublyList *create_list() {
    DoublyList *l = (DoublyList*)(malloc(sizeof(DoublyList)));
    if (l == NULL) {return 1;}
    l->first = NULL;
    l->last = NULL;
    l->counter = NULL;
}

int isEmpity(DoublyList *l) {
    if (l->counter == 0) {return 1;}
    return 0;
}

void insert_list(DoublyList *l, int value) {
    Node *p = (Node*)(malloc(sizeof(Node)));
    p->v = value;
    p->next = l->first;
    p->prev = NULL;

    if (isEmpity(l)) {l->first->prev = p;}
    else {l->last = p;}

    l->first = p;
    l->counter++;
}