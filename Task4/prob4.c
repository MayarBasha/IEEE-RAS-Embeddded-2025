#include <stdio.h>
#include <stdlib.h>

void EVEN(char *str){
while (*str != '\0') {

 if((*str-'0')%2==0){
    putchar(*str);
}
str++;
}
}

int main()
{

    char str;

 gets(&str);
 EVEN(&str);

 return 0;
}
