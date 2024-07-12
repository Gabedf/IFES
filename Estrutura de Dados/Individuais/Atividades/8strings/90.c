#include <stdio.h>
#include <string.h>

int main() {

    char word[100], drow[100];
    printf("Digite sua string: ");
    fgets(word, sizeof(word), stdin);

    int i, size;
    size = strlen(word);

    for (i = 0; size >= 0; size--) {
        drow[i] = word[size];
        i++;
    }

    printf("%s", word);
    printf("\n%s", drow);

    return 0;
}
