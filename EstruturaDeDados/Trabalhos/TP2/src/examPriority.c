#include <stdio.h>
#include <stdlib.h>
#include "examPriority.h"
#include "examNode.h"
#include "patient.h"

ExamPriority *createPriorityList() 
{
    ExamPriority *pl = (ExamPriority*)(malloc(sizeof(ExamPriority)));
    if (pl == NULL) {
        fprintf(stderr, "Erro ao alocar memória para a fila de prioridade.\n");
        exit(EXIT_FAILURE);
    }
    pl->front = pl->rear = NULL;
    pl->counter = 0;
    return pl;
}

void insertPriority(ExamPriority *ep, PriorityNode *node)
{
    node->next = NULL;
    if (ep->front == NULL) {
        ep->front = ep->rear = node;
    } else {
        PriorityNode *current = ep->front;
        PriorityNode *prev = NULL;

        while (current != NULL && current->severity >= node->severity) {
            prev = current;
            current = current->next;
        }

        if (prev == NULL) {
            node->next = ep->front;
            ep->front = node;
        } else {
            node->next = prev->next;
            prev->next = node;
        }

        if (node->next == NULL) {
            ep->rear = node;
        }
    }
    ep->counter++;
}

void printPritority(ExamPriority *ep) 
{
    if (ep->counter > 0) 
    {
        printf("Lista prioridade:\n");
        for (PriorityNode *p = ep->front; p != NULL; p = p->next) 
        {
            printf("Nome - %s | Severity - %d\n", p->patient->patient->name, p->severity);
        }
        printf("\n"); 
    }

}
