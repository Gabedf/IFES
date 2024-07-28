#include <stdio.h>

float calculate_bonus(int years_working, float salary) {
    float bonus;
    if ((years_working > 5) && (salary > 5000)) {
        bonus = salary * 0.1;
    } else {bonus = salary * 0.05;}

    return bonus;
}

int main() {
    int years_working;
    float salary, bonus;

    printf("How many year does the employe work here: ");
    scanf("%d", &years_working);

    printf("What is the salary today: ");
    scanf("%f", &salary);

    bonus = calculate_bonus(years_working, salary);
    printf("The bonus is %.2f $.", bonus);

    return 0;
}