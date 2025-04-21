#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1,num2;

    int *pNum1=&num1;
    int *pNum2=&num2;
    printf("enter first number \n");
    scanf("%d",pNum1);
    printf("enter the second number \n");
   scanf("%d",pNum2);

    printf("the sum = %d \n",(*pNum1)+ (*pNum2));
     printf("the difference = %d \n",(*pNum1)- (*pNum2));
      printf("the product = %d \n",(*pNum1)* (*pNum2));
      printf("the quotient = %d \n",(*pNum1)/ (*pNum2));



    return 0;
}
