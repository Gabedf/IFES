#ifndef PRIORITY
#define PRIORITY

#include "patient.h"

typedef struct exam_priority ExamPriority;
typedef struct priorityNode PriorityNode;

struct exam_priority {
    int counter;
    PriorityNode *front;
    PriorityNode *rear;
};

struct priorityNode {
    pNode *patient;
    PriorityNode *next;
    int severity;
    char condition[30];
    int conditionV;
    int id;
};

ExamPriority *createPriorityList();

void insertPriority(ExamPriority *ep, PriorityNode *node);

void printPritority(ExamPriority *ep);

void saveCondition(PriorityNode *priorityNode);

#endif
