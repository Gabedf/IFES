#include "report.h"
#include <stdio.h>
#include <stdlib.h>
#include "examPriority.h"
#include "condition.h"
#include <string.h>
#include "machineManager.h"
#include "oftenReport.h"

Report *new_report()
{
    Report *report = (Report*)(malloc(sizeof(Report)));
    report->counter = report->start_time = 0;
    report->node = NULL;
    report->patient = NULL;
    return report;
}

OftenReport *new_OftenReport()
{
    OftenReport *report = (OftenReport*)(malloc(sizeof(OftenReport)));
    report->totalPatients = report->examDone = report->pQueue = report->reportDone = report->startTime = 0;
    return report;
}

void confirmeCondition(Report *r) 
{
    float random_value = ((float)rand()) / RAND_MAX;
    if (random_value < 0.8) {return;}
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
}

void saveReport(Report *report) {
    FILE *file = fopen("db_report.txt", "a");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fprintf(file, "ID: %d, CONDITION: %s, SEVERITY: %d\n", report->patient->id, report->node->condition,  report->node->severity);

    fclose(file);
}

void insert_report(ExamPriority *ep, Report *report, int current_time, OftenReport *of)
{
    if (ep->rear != NULL) {
        if (report->start_time == 0) {report->start_time = current_time;}
        if ((current_time - report->start_time) >= 2) 
        {
            report->patient = ep->front->patient->patient;
            report->node = ep->front;
            ep->front = ep->front->next;
            ep->counter--;
            report->node->next = NULL;
            confirmeCondition(report);
            print_report(report);
            saveReport(report);
            report->node = NULL;     
            report->patient = NULL;
            report->start_time = 0;
            of->reportDone++;
        }            
    }
}

void print_reportDone(OftenReport *of, int current_time)
{
    if (of->startTime == 0) {of->startTime = current_time;}
    if ((current_time - of->startTime) >= 5) {
        float percentualDone = ((float)of->reportDone / of->examDone) * 100;
        printf("\nRELATÓRIO TOTAL: ");
        printf("\nPACIENTES TOTAL: %d\nPACIENTES EM FILA: %d\nEXAMES REALIZADOS: %d\nLAUDOS CONCLUÍDO: %d\nPORCENTAGEM PACIENTES COM LAUDO: %.2f\n\n", of->totalPatients, of->pQueue, of->examDone, of->reportDone, percentualDone);
        of->startTime = 0;
    }
}

void print_report(Report *r)
{
    {
        printf("Paciente:\n");
        printf("Nome - %s | Condition - %s | Severity - %d\n", r->patient->name, r->node->condition, r->node->severity);
    }
}
