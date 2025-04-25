#include <stdio.h>
#include <stdlib.h>

int compare(char *str1 , char *str2 ){
while (*str1!='\0'|| *str2!='\0'){
    if(*str1!= *str2){

        return 0;
    }

    str1++;
    str2++;

}

return 1;

}

int main()
{

   char string1[100];
    char string2[100];

    printf("Enter String1: ");
    fgets(string1, sizeof(string1), stdin);

    printf("Enter String2: ");
    fgets(string2, sizeof(string2), stdin);

    // Remove newline characters if present
    for (int i = 0; string1[i] != '\0'; i++) {
        if (string1[i] == '\n') {
            string1[i] = '\0';
            break;
        }
    }

    for (int i = 0; string2[i] != '\0'; i++) {
        if (string2[i] == '\n') {
            string2[i] = '\0';
            break;
        }
    }

    if (compare(string1, string2)) {
        printf("Both strings are Identical\n");
    } else {
        printf("Strings are Not Identical\n");
    }

    return 0;
}
