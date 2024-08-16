#ifndef MY_PATIENT
#define MY_PATIENT

typedef struct patient Patient;
typedef struct p_queu pQueue;
typedef struct p_node pNode;

struct patient 
{
    int id;
    char name[100];
    time_t arrival_time;
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
};

// 
Patient *create_patient(int id, const char *name, time_t arrival_time);

// 
pQueue *create_Queue();

//
void insertPatient(pQueue *q, Patient *p);

//
void savePatient(Patient *patient);

#endif