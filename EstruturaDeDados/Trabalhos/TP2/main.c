#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> 
#include "machineManager.h"
#include "patient.h"
#include "examPriority.h"

int main() {
    ExamList *examList = createExamList();
    pQueue *patientQueue = create_Queue();
    ExamPriority *examPriority = createPriorityList();
    int current_time = 0, end = 1, patient_id = 0;

    while (1) {
        current_time++;

        // ARRUMAR PARA 20%
        if (rand() % 100 < 100) {
            char patient_name[100];
            patient_id++;

            printf("Novo paciente chegou! Insira os dados!\n");
            printf("Nome do Paciente: ");
            scanf("%s", patient_name);

            Patient *new_patient = create_patient(patient_id, patient_name, current_time);
            savePatient(new_patient);
            insertPatient(patientQueue, new_patient);
            printPq(patientQueue);
            printMachine(examList);
            printPritority(examPriority);
            printf("\nDigite '0' caso deseja encerrar ou '1' para continuar: ");
            scanf("%d", &end);
            if (end == 0)  {break;}
        }

        insertMachine(examList, patientQueue, current_time);

        updateExamStatus(examList, examPriority, current_time);

        sleep(0.2);
    }

    return 0;
}
