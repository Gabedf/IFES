#include "include/patient.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    // Criar uma fila
    pQueue *queue = create_Queue();

    // Criar pacientes
    Patient *patient1 = create_patient(1, "John Doe");
    Patient *patient2 = create_patient(2, "Jane Smith");

    // Inserir pacientes na fila
    insertPatient(queue, patient1);
    insertPatient(queue, patient2);

    // Salvar pacientes em um arquivo
    savePatient(patient1);
    savePatient(patient2);

    // Liberar memória
    free(patient1);
    free(patient2);
    free(queue);

    return 0;
}
