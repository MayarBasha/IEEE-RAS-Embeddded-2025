#include <stdio.h>
#include <stdlib.h>

int main()
{
  int age =5;
  int *pAge = &age;
  printf("the age %d\n",age);
  printf("the address of age %p\n",&age);
  printf("the age %d\n",*pAge);
  printf("the address of age %p\n",pAge);

  float length = 12.5;
  float *pLength=&length;
   printf("the length %f\n",length);
  printf("the address of length %p\n",(void*)&length);
  printf("the length %f\n",*pLength);
  printf("the address of length %p\n",(void*)pLength);

  long people =1259956655656;
  long *pPeople = &people;
   printf("the people %ld\n",people);
  printf("the address of people %p\n",&people);
  printf("the age %ld\n",*pPeople);
  printf("the address of people %p\n",pPeople);

  char letter ='M';
  char *pLetter =&letter;
    printf("the letter %c\n",letter);
  printf("the address of letter %p\n",(void*)&letter);
  printf("the letter %c\n",*pLetter);
  printf("the address of letter %p\n",(void*)pLetter);

    return 0;
}
