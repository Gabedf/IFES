#ifndef EXAM_NODE_H
#define EXAM_NODE_H

#include "patient.h"

typedef struct exam_node ExamNode;

struct exam_node {
    pNode *patient;
    ExamNode *next;
    int severity;
    int start_time;
};

#endif
