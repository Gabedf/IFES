#ifndef MY_MACHINE
#define MY_MACHINE
#define EXAM_DURATION 10

typedef struct exam ExamList;
typedef struct exam_node ExamNode;

struct exam_list 
{
    int counter;
    examNode *front;
    examNode *rear;
};

struct exame_node 
{
    Patient *patient;
    examNode *next;
    int severity;
    int start_time;
};

int determine_condition();

examList *createExamList();

int full(examList *el);

int empity(examList *el);

void insertMachine(ExamList *el, pQueue *q);

void updateExamStatus(ExamList *el, int current_time);

#endif