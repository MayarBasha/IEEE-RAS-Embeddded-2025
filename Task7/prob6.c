#include <stdio.h>
#include <stdlib.h>

union types{
int A;
float B;
char C;
};

int main()
{
 union types var;
  var.A = 5;
  printf("%d\n",var.A);
   printf("%f\n",var.B);
    printf("%c\n",var.C);
    printf("*************************\n");
var.B=2.5;
 printf("%d\n",var.A);
  printf("%f\n",var.B);
   printf("%c\n",var.C);
  printf("*************************\n");
   var.C='M';
    printf("%d\n",var.A);
    printf("%f\n",var.B);
     printf("%c\n",var.C);
    return 0;
}
