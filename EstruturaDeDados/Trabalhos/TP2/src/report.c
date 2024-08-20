#include "report.h"
#include <stdio.h>
#include <stdlib.h>
#include "examPriority.h"
#include "condition.h"
#include <string.h>
#include "machineManager.h"

Report *new_report()
{
    Report *report = (Report*)(malloc(sizeof(Report)));
    report->counter = 0;
    report->node = NULL;
    return report;
}

Report *confirmeCondition(Report *r) 
{
    float random_value = ((float)rand()) / RAND_MAX;
    if (random_value < 0.8) {return r;}
    else 
    {
        int conditionV = determine_condition();
        while (conditionV == r->node->conditionV)
        {
            conditionV = determine_condition();
        }
        r->node->severity = determine_severity(conditionV);
        r->node->conditionV = conditionV;
        char *conditionName = condition(conditionV);
        strcpy(r->node->condition, conditionName);
    }
    return r;
}

void saveReport(Report *r) {
    FILE *file = fopen("db_report.txt", "a");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fprintf(file, "ID: %d, CONDITION: %s, SEVERITY: %d\n", r->node->patient->patient->id, r->node->condition,  r->node->severity);
    r->counter = 0;
    fclose(file);
}

void insert_report(ExamPriority *ep, Report *report, int current_time, int id)
{
    if (ep != NULL) {
        if (report->start_time == 0) {report->start_time = current_time;}
        if ((report->counter < 1 && ep->counter > 0) || report->node->patient->patient->id == id)
        {
            if ((current_time - report->start_time) >= 4) 
            {
                report->node = ep->front;
                ep->front = ep->front->next;
                ep->counter--;
                report->node->next = NULL;
                saveReport(report);
            }   
        }
    }

}

void print_report(Report *r)
{
    if (r->counter > 0)
    {
        printf("Paciente:\n");
        printf("Nome - %s | Condition - %s | Severity - %d\n", r->node->patient->patient->name, r->node->condition, r->node->severity);
    }
}