#include <stdio.h>
#include <stdlib.h>

int main()
{
    float numbers;
float Max=0,Min=0;
int count =1;

 printf("Enter the numbers :\n");
 while (1){

 scanf("%f" , &numbers);
 //to exit the loop after enter -1
 if (numbers== -1){
        break;
}
//to initialize max and min with first number
if (count){
    Max =Min =numbers;
 count =0;
}
//get the maximum and minimum numbers
else{
    if ( numbers> Max){
     Max = numbers;
    }
    if( numbers < Min  ){
    Min = numbers;
    }
}
 }

 printf("Max = %f , Min = %f ", Max,Min);

    return 0;
}

