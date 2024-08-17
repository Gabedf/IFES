#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "patient.h"
#include <time.h>

Patient *create_patient(int id, const char *name, int arrival_time) 
{
    Patient *p = (Patient *)malloc(sizeof(Patient));
    if (p == NULL) {
        fprintf(stderr, "Erro ao alocar memória para a fila.\n");
        exit(EXIT_FAILURE);
    }

    p->id = id;
    p->arrival_time = arrival_time;
    strcpy(p->name, name);
    
    return p;
}

pQueue *create_Queue() 
{
    pQueue *q = (pQueue*)(malloc(sizeof(pQueue)));
    if (q == NULL) {
        fprintf(stderr, "Erro ao alocar memória para a fila.\n");
        exit(EXIT_FAILURE);
    }
    q->front = q->rear = NULL;
    q->counter = 0;
    return q;
}

void insertPatient(pQueue *q, Patient *p)
{
    pNode *node = (pNode*)(malloc(sizeof(pNode)));
    if (node == NULL) {
        fprintf(stderr, "Erro ao alocar memória para a fila.\n");
        exit(EXIT_FAILURE);
    }
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

    fprintf(file, "%d, %s\n", patient->id, patient->name);

    fclose(file);
}
