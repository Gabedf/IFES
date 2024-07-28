#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void extract_date(char date[], char *day, char *month, char *year) {

    for (int i = 0; i < 2; i++) {
        day[i] = date[i];
    } day[2] = '\0';
    
    for (int i = 3; i < 5; i++) {
        month[i - 3] = date[i];
    }  month[2] = '\0';

    for (int i = 6; i < 10; i++) {
        year[i - 6] = date[i];
    } year[4] = '\0';
}

int main() {
    char date[11], day[3], month[3], year[5];

    printf("Enter the date (DD/MM/YYYY): ");
    scanf("%s", &date);

    extract_date(date, day, month, year);

    printf("The day is: %s\n", day);
    printf("The month is: %s\n", month);
    printf("The year is: %s\n", year);

    return 0;
}