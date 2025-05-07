#include <stdio.h>
#include <stdlib.h>

int main()
{
int n ,sum =0;
printf("enter rhe number of array ");
scanf("%d",&n);
int* arr =(int*)malloc(n*sizeof(int));
if (arr==NULL){
    printf("memory allocation failed ");

    return 1;
}
printf("enter the elements of the array:\n ");
for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
sum+=arr[i];
}


printf("the sum of the elements = %d",sum);
    free(arr);

    return 0;
}
