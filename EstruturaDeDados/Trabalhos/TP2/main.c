#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> 
#include "machineManager.h"
#include "patient.h"
#include "examPriority.h"
#include "report.h"

int main() {
    ExamList *examList = createExamList();
    pQueue *patientQueue = create_Queue();
    ExamPriority *examPriority = createPriorityList();
    Report *report = new_report();
    OftenReport *oReport = new_OftenReport();
    int current_time = 0, patient_id = 0;

    while (current_time < 43200) {
        current_time++;

        if (rand() % 100 < 20) {
            char patient_name[100];
            patient_id++;

            printf("Novo paciente chegou! Insira os dados!\n");
            printf("Nome do Paciente: ");
            scanf("%s", patient_name);

            Patient *new_patient = create_patient( patient_id, patient_name, current_time);
            savePatient(new_patient);
            insertPatient(patientQueue, new_patient, oReport);
            insert_report(examPriority, report, current_time, oReport);
            print_reportDone(oReport, current_time);
        }

        insertMachine(examList, patientQueue, current_time, oReport);

        updateExamStatus(examList, examPriority, current_time, oReport);
        sleep(5);
    }

    return 0;
}
