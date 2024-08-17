#ifndef MY_MACHINE
#define MY_MACHINE
#define EXAM_DURATION 10
#include "patient.h"

typedef struct exam_list ExamList;
typedef struct exam_node ExamNode;

struct exam_list 
{
    int counter;
    ExamNode *front;
    ExamNode *rear;
};

struct exam_node 
{
    pNode *patient;
    ExamNode *next;
    int severity;
    int start_time;
};

int determine_condition();

ExamList *createExamList();

int full(ExamList *el);

int empity(ExamList *el);

void insertMachine(ExamList *el, pQueue *q);

void updateExamStatus(ExamList *el, int current_time);

#endif