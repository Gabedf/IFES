#ifndef OFTENREPORT
#define OFTENREPORT

typedef struct oftenReport OftenReport;

struct oftenReport
{
    int startTime;
    int totalPatients;
    int pQueue;
    int examDone;
    int reportDone;
};

OftenReport *new_OftenReport();

void print_reportDone(OftenReport *of, int current_time);

#endif