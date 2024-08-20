#ifndef REPORT
#define REPORT

#include "examPriority.h"

typedef struct report Report;

struct report 
{  
    int counter;
    int start_time;
    PriorityNode *node;
};

Report *new_report();

void insert_report(ExamPriority *ep, Report *report, int current_time, int id);

Report *confirmeCondition(Report *r);

void saveReport(Report *r);

void print_report(Report *r);

#endif