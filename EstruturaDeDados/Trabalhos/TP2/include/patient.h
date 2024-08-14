#ifndef PATIENT
#define PATIENT

typedef struct patient Patient;
typedef struct p_queu pQueue;
typedef struct p_node pNode;

struct patient 
{
    int id;
    char name[100];
};

struct p_queu
{
    int counter;
    pNode *front;
    pNode *rear; 
};

struct p_node
{
    Patient *patient;
    pNode *next;
}

// 
Patient *create_patient(int id, const char name);

// 
pQueue *create_Queue();

//
void insertPatient(pQueue *q, Patient *p);
#endif