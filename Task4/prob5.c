#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int STRING (const char *str){

  int count = 0;
    while (*str != '\0') {
        count++;
        str++;
    }
    return count;
}


int main()
{
    char str[100];
    gets(&str);
int length = STRING(str);
printf("the length = %d ",length);
    return 0;
}
