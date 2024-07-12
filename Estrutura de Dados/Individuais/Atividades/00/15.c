#include <stdio.h>

int main() {
    int water;
    float tax, bill;
    
    printf("Type how many m³ of water was used this month: ");
    scanf("%d", &water);

    if (water < 11) {
        tax = water * 0.69;
    }
    else if (water < 16) {
        tax = water * 1.17;
    }
    else if (water < 26) {
        tax = water * 1.48;
    }
    else {
        tax = water * 1.60;
    }

    bill = tax + (tax*0.025) + 5;
    printf("Your total bill was %.2f", bill);

    return 0;
}