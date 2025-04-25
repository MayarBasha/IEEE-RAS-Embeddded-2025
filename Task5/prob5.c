#include <stdio.h>
#include <stdlib.h>
   int count;
void odd(int *arr,int n){

for(int i=0;i<n;i++){
if(arr[i]%2!=0){
    printf("%d ",arr[i]);
    count++;
}

}

}

int main()
{
    int n;
    printf("enter the number of elements: ");
    scanf("%d",&n);

    int arr[n];
    printf("enter the array: \n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);

    }

    odd(arr,n);

printf("\nTotal odd numbers: %d",count);
    return 0;
}
