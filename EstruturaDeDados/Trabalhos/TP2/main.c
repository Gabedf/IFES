#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "machine_manager.h"
#include "patient.h"

int main() {
    ExamList *examList = createExamList();
    pQueue *patientQueue = create_Queue();
    int current_time = 0, end = 1, patient_id = 0;

    while (1) {
        // Atualiza o tempo atual
        current_time++;

        // 20% de chance de chegar um novo paciente
        if (rand() % 100 < 20) {
            char patient_name[100];
            patient_id++;

            printf("Novo paciente chegou! Insira os dados:\n");
            printf("Nome do Paciente: ");
            scanf("%s", patient_name);

            Patient *new_patient = create_patient(patient_id, patient_name, current_time);
            savePatient(new_patient);
            insertPatient(patientQueue, new_patient);

            printf("Paciente %d (%s) foi adicionado à fila no tempo %d.\n", patient_id, patient_name, current_time);

            printf("Digite '0' caso deseja encerrar ou '1' para continuar: ");
            scanf("%d", &end);
            if (end == 0)  {break;}
        }

        // Aloca pacientes em máquinas, se disponíveis
        insertMachine(examList, patientQueue, current_time);

        // Atualiza status dos exames (remove exames concluídos)
        updateExamStatus(examList, current_time);

    }

    return 0;
}
