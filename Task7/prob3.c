#include <stdio.h>
#include <stdlib.h>

typedef struct complex_number{
float real;
float imag;

}Complex;

void addCompNumbers(Complex comp1,Complex comp2){
float realSum=comp1.real+comp2.real;
float imagSum=comp1.imag+comp2.imag;
printf("the sun of numbers = %.1f + %.1f i",realSum,imagSum);


}

int main()
{
  Complex com1;
  Complex com2;
  com1.real = 4;
  com1.imag=  3;
  com2.real = 6;
  com2.imag=  8;

  addCompNumbers(com1,com2);

    return 0;
}
