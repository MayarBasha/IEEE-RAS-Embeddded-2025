#include <stdio.h>
#include <stdlib.h>

//#define addNumbers
#define subNumbers

#ifdef addNumbers
#define operation getAndAdd

#elif defined(subNumbers)
#define operation getAndSub
#endif

int* getAndAdd(){
int num1;
int num2;
printf("enter the first num: ");
scanf("%d",&num1);
printf("enter the second number: ");
scanf("%d",&num2);
return (num1+num2);
}
int* getAndSub(){
int num1;
int num2;
printf("enter first num: ");
scanf("%d",&num1);
printf("enter the second number: ");
scanf("%d",&num2);
return (num1-num2);

}

int main()
{
int* op = operation();
printf("the operation between two numbers= %d",op);


    return 0;
}
