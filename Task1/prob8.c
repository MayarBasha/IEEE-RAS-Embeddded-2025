#include <stdio.h>
#include <stdlib.h>

int main()
{
   float  num,sum=0;
   printf("Enter a number: ");
   scanf("%f",&num);
//to prevent user to enter float number
   if (num -(int)num !=0){
    printf("%.1f is not a perfect number " ,num);

   }
   else{
   for(int i=1;i<num;i++){
    if ((int)num%i ==0){
        sum +=i;
    }
   }

   if(sum == num && num >=0){
    printf("%.f Is a perfect number",num);
   }
   else{
    printf("%.f Is not a perfect number",num);
   }

   }
    return 0;
}
