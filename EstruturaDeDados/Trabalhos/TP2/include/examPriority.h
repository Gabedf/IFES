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
};

ExamPriority *createPriorityList();

void insertPriority(ExamPriority *ep, PriorityNode *node);

void printPritority(ExamPriority *ep);

#endif
