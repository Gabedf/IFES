#ifndef MY_PATIENT
#define MY_PATIENT
#include <time.h>
#include "oftenReport.h"

typedef struct patient Patient;
typedef struct p_queu pQueue;
typedef struct p_node pNode;

struct patient 
{
    int id;
    char name[100];
    int arrival_time;
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
Patient *create_patient(int id, const char *name, int arrival_time);

// 
pQueue *create_Queue();

//
void insertPatient(pQueue *q, Patient *p, OftenReport *or);

//
void savePatient(Patient *patient);

void printPq(pQueue *pq);

#endif