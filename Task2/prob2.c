#include <stdio.h>
#include <stdlib.h>

int main()
{

 int num ;
 scanf("%d" , &num);
 int temp=num ,Rem,Res;
 while (temp !=0){
 Rem= temp %10;
 Res +=Rem*Rem*Rem;
temp /=10;
 }
 if (num == Res){
 printf("%d is an armstrong number",num);
 }
  else{
 printf("%d is not an armstrong number",num);
 }


    return 0;
}
