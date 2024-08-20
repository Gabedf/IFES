#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "examNode.h"
#include "machineManager.h"
#include "patient.h"
#include "examPriority.h"
#include "condition.h"

ExamList *createExamList() 
{
    ExamList *el = (ExamList*)(malloc(sizeof(ExamList)));
    if (el == NULL) {
        fprintf(stderr, "Erro ao alocar memória para a fila de exames.\n");
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

int empty(ExamList *el) 
{
    return el->counter == 0;
}

void insertMachine(ExamList *el, pQueue *q, int current_time) {
    if (full(el) || q->front == NULL) {
        return;
    }

    ExamNode *node = (ExamNode*)malloc(sizeof(ExamNode));
    if (node == NULL) {
        fprintf(stderr, "Erro ao alocar memória para a fila de exames.\n");
        exit(EXIT_FAILURE);
    }

    node->start_time = current_time;
    node->next = NULL;
    node->patient = q->front; 

    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }

    if (el->counter == 0) {
        el->front = node;
    } else {
        el->rear->next = node;
    }

    el->rear = node;
    el->counter++;
    q->counter--;
}

void updateExamStatus(ExamList *el, ExamPriority *ep, int current_time) 
{
    if (el->counter == 0) return;

    ExamNode *prev = NULL;
    ExamNode *node = el->front;

    while (node != NULL) 
    {
        if ((current_time - node->start_time) >= EXAM_DURATION) 
        {
            int conditionV = determine_condition();
            char *conditionName = condition(conditionV);
            node->severity = determine_severity(conditionV);

            if (prev == NULL) {
                el->front = node->next;
            } else {
                prev->next = node->next;
            }

            if (node == el->rear) {
                el->rear = prev;
            }

            el->counter--;

            PriorityNode *priorityNode = (PriorityNode *)malloc(sizeof(PriorityNode));
            if (priorityNode == NULL) {
                fprintf(stderr, "Erro ao alocar memória para a fila de prioridade.\n");
                exit(EXIT_FAILURE);
            }

            priorityNode->patient = node->patient;
            priorityNode->conditionV = conditionV;
            priorityNode->severity = node->severity;
            strcpy(priorityNode->condition, conditionName);

            insertPriority(ep, priorityNode);
            saveCondition(priorityNode);
            node = (prev == NULL) ? el->front : prev->next;
        } 
        else 
        {
            prev = node;
            node = node->next;
        }
    }
}

void printMachine(ExamList *el) 
{
    if (el->counter > 0) 
    {
        printf("Lista máquinas:\n");
        for (ExamNode *p = el->front; p != NULL; p = p->next) 
        {
            printf("Nome - %s;\n", p->patient->patient->name);
        }
        printf("\n");
    }
}