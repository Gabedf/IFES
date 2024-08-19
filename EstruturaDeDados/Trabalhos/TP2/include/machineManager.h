#ifndef MY_MACHINE
#define MY_MACHINE

#define EXAM_DURATION 4

#include "examPriority.h"
#include "examNode.h"
#include "patient.h"

typedef struct exam_list ExamList;

struct exam_list {
    int counter;
    ExamNode *front;
    ExamNode *rear;
};

int determine_condition();

ExamList *createExamList();

int full(ExamList *el);

int empty(ExamList *el);

void insertMachine(ExamList *el, pQueue *q, int current_time);

void updateExamStatus(ExamList *el, ExamPriority *ep, int current_time);

void printMachine(ExamList *el);

#endif
