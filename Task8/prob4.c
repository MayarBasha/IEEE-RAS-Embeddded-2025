#include <stdio.h>
#include <stdlib.h>

int main()
{
  int *arrMalloc, *arrCalloc, *biggerArrMalloc;
  int i;

  arrMalloc=(int *)malloc(5*sizeof(int));
  if (arrMalloc==NULL){
    printf("memory allocation using malloc failed");
return 1;
  }
for(i=0;i<5;i++){
   arrMalloc[i]=i;
}
 printf("the values in arrMalloc : \n");
  for(i=0;i<5;i++){
    printf(" %d ",arrMalloc[i]);
  }

  printf("\n");
   arrCalloc=(int *)calloc(5,sizeof(int));
  if (arrCalloc==NULL){
    printf("memory allocation using calloc failed");
    free(arrMalloc);
return 1;
  }
for(i=0;i<5;i++){
   arrCalloc[i]=i+2;
}
 printf("the values in arrCalloc : \n");
  for(i=0;i<5;i++){
    printf(" %d ",arrCalloc[i]);
  }

  printf("\n");
free(arrMalloc);

   biggerArrMalloc=(int *)malloc(50*sizeof(int));
  if (biggerArrMalloc==NULL){
    printf("memory allocation using Malloc failed");
  free(arrCalloc);
return 1;
  }

for(i=0;i<50;i++){
   biggerArrMalloc[i]=i*10;
}

 printf("the values in biggerArrMalloc : \n");
  for(i=0;i<50;i++){
    printf(" %d ",biggerArrMalloc[i]);
  }


 free(biggerArrMalloc);
    free(arrCalloc);

    return 0;
}
