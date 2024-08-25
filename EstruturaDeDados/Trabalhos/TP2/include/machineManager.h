#ifndef MY_MACHINE
#define MY_MACHINE

#define EXAM_DURATION 10

#include "examPriority.h"
#include "examNode.h"
#include "patient.h"
#include "oftenReport.h"

typedef struct exam_list ExamList;

struct exam_list {
    int counter;
    ExamNode *front;
    ExamNode *rear;
};

ExamList *createExamList();

int full(ExamList *el);

int empty(ExamList *el);

void insertMachine(ExamList *el, pQueue *q, int current_time, OftenReport *of);

void updateExamStatus(ExamList *el, ExamPriority *ep, int current_time, OftenReport *of);

void printMachine(ExamList *el);

#endif
