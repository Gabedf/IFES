#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <patient.h>

Patient *create_patient(int id, const char *name) 
{
    Patient *p = (Patient *)malloc(sizeof(Patient));
    if (p == NULL) {exit(1);}

    p->id = id;
    strcpy(p->name, name);

    return p;
}

pQueue *create_Queue() 
{
    pQueue *q = (pQueue*)(malloc(sizeof(pQueue)));
    if (q == NULL) {exit(1);}
    q->front = q->rear = NULL;
    q->counter = 0;
    return q;
}

void insertPatient(pQueue *q, Patient *p)
{
    pNode *node = (pNode*)(malloc(sizeof(pNode)));
    node->patient = p;
    node->next = NULL;

    if (q->counter == 0) {q->front = node;}
    else {q->rear->next = node;}

    q->rear = node;
    q->counter++;
}

void savePatient(Patient *patient) {
    FILE *file = fopen("db_patient.txt", "a");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fprintf(file, "%d %s %s", *patient.id, *patient.name);

    fclose(file);
}