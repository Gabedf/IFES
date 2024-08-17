#include <stdio.h>
#include <stdlib.h>
#include "machine_manager.h"
#include "patient.h"
#include <time.h>

int determine_condition() {
    float random_value = ((float)rand()) / RAND_MAX;
    
    if (random_value < 0.3) return 1;   // Saúde Normal
    if (random_value < 0.5) return 2;   // Bronquite
    if (random_value < 0.6) return 3;   // Pneumonia
    if (random_value < 0.7) return 4;   // COVID
    if (random_value < 0.75) return 4;  // Embolia pulmonar
    if (random_value < 0.80) return 4;  // Derrame pleural
    if (random_value < 0.85) return 5;  // Fibrose pulmonar
    if (random_value < 0.90) return 5;  // Tuberculose
    return 6;                           // Câncer de pulmão
}

ExamList *createExamList() 
{
    ExamList *el = (ExamList*)(malloc(sizeof(ExamList)));
    if (el == NULL) {
        fprintf(stderr, "Erro ao alocar memória para a fila.\n");
        exit(EXIT_FAILURE);
    }
    el->front = el->rear = NULL;
    el->counter = 0;
    return el;
}

int full(ExamList *el) 
{
    return el->counter == 5;
}

int empity(ExamList *el) 
{
    return el->counter == 0;
}

void insertMachine(ExamList *el, pQueue *q, int current_time)
{
    ExamNode *node = (ExamNode*)(malloc(sizeof(ExamNode)));
    if (node == NULL) {
        fprintf(stderr, "Erro ao alocar memória para a fila.\n");
        exit(EXIT_FAILURE);
    }
    
    node->severity = 0;
    node->start_time = current_time;
    node->next = NULL;
    node->patient = NULL;

    if (q->rear == NULL) 
    {   
        free(node);
        return;
    }

    if (full(el) || q->front == NULL) {return; }

    if (el->counter == 0) {el->front = node;}
    else {el->rear->next = node;}
    
    node->start_time = current_time;
    node->severity = determine_condition();
    node->patient = q->front;
    q->front = q->front->next;
    node->patient->next = NULL;

    el->rear = node;
    el->counter++;
    q->counter--;
}

void updateExamStatus(ExamList *el, int current_time) 
{
    if (el->counter == 0) {return;}

    ExamNode *prev = NULL;
    ExamNode *node = el->front;

    while (node != NULL) 
    {
        if ((current_time - node->start_time) >= EXAM_DURATION) 
        {
            
            if (prev == NULL) {el->front = node->next;} 
            else {prev->next = node->next;}

            if (node == el->rear) {el->rear = prev;}

            ExamNode *temp = node;
            node = node->next;
            free(temp);
            el->counter--;
        } 
        
        else 
        {
            prev = node;
            node = node->next;
        }
    }
}