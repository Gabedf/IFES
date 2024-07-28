#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char s1[100], s2[100];

    printf("Enter a word: ");
    fgets(s1, sizeof(s1), stdin);
    getchar();
    int i = 0, n1 = strlen(s1);

    printf("\nEnter another word: ");
    fgets(s2, sizeof(s2), stdin);    
    getchar();

    int n2 = strlen(s2);
    int n3 = n1 + n2;
    char **s3 = (char*)(malloc(n3*sizeof(char)));

    while (s1[i] != '\0' && s2[i] != '\0') {
        s3[strlen(s3)] = s1[i];
        s3[strlen(s3) + 1] = s2[i];
        i++;
    }

    printf("The final string is: %s", s3);

    return 0;
}