#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "patient.h"
#include "machine_manager.h"

int main() {
    // Inicializar fila de pacientes e lista de exames
    pQueue *patientQueue = create_Queue();
    ExamList *machineList = createExamList();

    // Simular tempo
    int current_time = 0;
    
    // Criar alguns pacientes e inseri-los na fila
    time_t arrival_time = time(NULL);
    insertPatient(patientQueue, create_patient(1, "John Doe", arrival_time));
    insertPatient(patientQueue, create_patient(2, "Jane Smith", arrival_time + 1));
    insertPatient(patientQueue, create_patient(3, "Bob Brown", arrival_time + 2));

    // Simular alocação de pacientes nas máquinas
    while (patientQueue->counter > 0 || machineList->counter > 0) {
        printf("Current Time: %d\n", current_time);

        // Inserir paciente na máquina se disponível
        insertMachine(machineList, patientQueue);

        // Atualizar status dos exames
        updateExamStatus(machineList, current_time);

        // Incrementar o tempo
        current_time++;
    }

    // Finalizar
    printf("All patients have been processed.\n");
    return 0;
}
