#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "condition.h"

int determine_condition() 
{
    float random_value = ((float)rand()) / RAND_MAX;
    
    if (random_value < 0.3) return 1;   // Saúde Normal
    if (random_value < 0.5) return 2;   // Bronquite
    if (random_value < 0.6) return 3;   // Pneumonia
    if (random_value < 0.7) return 4;   // COVID
    if (random_value < 0.75) return 5;  // Embolia pulmonar
    if (random_value < 0.80) return 6;  // Derrame pleural
    if (random_value < 0.85) return 7;  // Fibrose pulmonar
    if (random_value < 0.90) return 8;  // Tuberculose
    return 9;                           // Câncer de pulmão
}

int determine_severity(int v)
{
    if (v == 1) return 1;
    if (v == 2) return 2;
    if (v == 3) return 3;
    if (v == 4 || v == 5 || v == 6) return 4;
    if (v == 7 || v == 8) return 5;
    else return 6;
}

char *condition(int v) 
{
    if (v == 1) return "Saúde Normal";   
    if (v == 2) return "Bronquite";   
    if (v == 3) return "Pneumonia"; 
    if (v == 4) return "COVID";   
    if (v == 5) return  "Embolia pulmonar";  
    if (v == 6) return "Derrame pleural";  
    if (v == 7) return "Fibrose pulmonar";  
    if (v == 8) return "Tuberculose";  
    return "Câncer de pulmão";  
}