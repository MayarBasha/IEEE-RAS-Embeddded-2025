#include <stdio.h>

void copyString(char *source, char *destination) {
    while (*source != '\0') {
        *destination = *source;
        source++;
        destination++;
    }
    *destination = '\0';

int main() {
    char originalString[100];
    char copiedString[100];

    printf("str: ");
    fgets( originalString, sizeof( originalString), stdin);


    for (int i = 0;  originalString[i] != '\0'; i++) {
        if ( originalString[i] == '\n') {
            originalString[i] = '\0';
            break;
        }
    }

    copyString( originalString, copiedString);
    printf("original string: %s\n", originalString);

    printf("Copied String: %s\n", copiedString);

    return 0;
}

