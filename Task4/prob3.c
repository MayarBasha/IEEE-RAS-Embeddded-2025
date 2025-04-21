#include <stdio.h>
#include <stdlib.h>
void swap(int *A,int *B){
int temp =*A;
*A = *B;
*B=temp;

}

int main()
{
    int num1 , num2;
    int *pNum1=&num1;
    int *pNum2=&num2;
    printf("enter the first number\n");
    scanf("%d",pNum1);
    printf("enter the second number\n");
    scanf("%d",pNum2);

    swap(pNum1,pNum2);
    printf("the numbers after swapping\n");
    printf("num1= %d, num2= %d ",*pNum1,*pNum2);
    return 0;
}
