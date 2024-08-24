#ifndef REPORT
#define REPORT

#include "examPriority.h"
#include "patient.h"

typedef struct report Report;

struct report 
{  
    int counter;
    int start_time;
    Patient *patient;
    PriorityNode *node;
};

Report *new_report();

void insert_report(ExamPriority *ep, Report *report, int current_time, OftenReport *of);

void confirmeCondition(Report *r);

void saveReport(Report *r);

void print_report(Report *r);

#endif