#include <stdio.h>
#include <stdlib.h>

typedef int integer;
typedef char character;
typedef long int ll;
typedef unsigned int uInteger;
typedef short int shInteger;
typedef double decimal;
typedef float  f;

int main()
{
  printf("size of int: %d\n",sizeof(integer));
   printf("size of int: %d\n",sizeof(integer));
    printf("size of char: %d\n",sizeof(character));
     printf("size of long int: %d\n",sizeof(ll));
      printf("size of unsigned int: %d\n",sizeof(uInteger));
       printf("size of short int:  %d\n",sizeof(shInteger));
    printf("size of double: %d\n",sizeof(decimal));
    printf("size of float: %d\n",sizeof(f));

    return 0;
}
