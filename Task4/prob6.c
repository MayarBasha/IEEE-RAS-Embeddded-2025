#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=7;
    int *aptr=&a;
    printf("Address of a is %p \nvalue of aptr is %p \n\n",&a,aptr);

     printf("Value of a is %d \nvalue of *aptr is %d \n\n",a,*aptr);

    printf("showing that * and & are complements of each other \n");
/*       & - Address-of Operator
    Used to get the address of a variable.

         * - Dereference Operator
    Used to get the value stored at the address that a pointer points to.

        &a gets the address of a
        *(&a) dereferences that address — gets back the value of a
       So, *(&a) is equivalent to a

       *p gets the value at address p (which is a)
      &(*p) gets the address of that value — which is p (i.e., &a)
    So, &(*p) is equivalent to p

    */

    printf("&*aptr = %p\n*&aptr = %p\n",&*aptr,*&aptr);




    return 0;
}
