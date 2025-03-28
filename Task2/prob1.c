#include <stdio.h>
#include <stdlib.h>
#include<math.h>


float isDivisible(float x ,float y )
{
    if(fmod(x,y)==0){
    return 1;
    }
    else if (fmod(x,y)!=0){
        return 0;
    }
}

int main()
{
    float num1 , num2 ;
    scanf("%f %f",&num1,&num2);

    if(isDivisible(num1,num2)==1){
        printf("%.1f is divisible by %.2f ",num1,num2);
    }
    else if(isDivisible(num1,num2)==0){
        printf("%.2f is not divisible by %.2f",num1,num2);
    }

    return 0;
}
