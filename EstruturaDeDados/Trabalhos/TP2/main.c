#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "machine_manager.h"
#include "patient.h"

int main() {
    ExamList *examList = createExamList();
    pQueue *patientQueue = create_Queue();

    int current_time = 0;

    while (1) {
        // Atualiza o tempo atual
        current_time++;

        // 20% de chance de chegar um novo paciente
        if (rand() % 100 < 20) {
            int patient_id;
            char patient_name[100];

            printf("Novo paciente chegou! Insira os dados:\n");
            printf("ID do Paciente: ");
            scanf("%d", &patient_id);
            printf("Nome do Paciente: ");
            scanf("%s", patient_name);

            Patient *new_patient = create_patient(patient_id, patient_name, current_time);
            insertPatient(patientQueue, new_patient);

            printf("Paciente %d (%s) foi adicionado à fila no tempo %d.\n", patient_id, patient_name, current_time);
        }

        // Aloca pacientes em máquinas, se disponíveis
        insertMachine(examList, patientQueue);

        // Atualiza status dos exames (remove exames concluídos)
        updateExamStatus(examList, current_time);

        // Simula o tempo passando (1 minuto = 1 unidade de tempo)
        // Pode-se adicionar um delay de 1 segundo para simular o tempo real.
        // Para evitar "sleep", comente a linha abaixo se estiver compilando para testes rápidos.
        // sleep(1);
    }

    return 0;
}
