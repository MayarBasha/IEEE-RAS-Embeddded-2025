#include <stdio.h>
#include <stdlib.h>

int main(){
    int matrix1[3][3];
    int matrix2[3][3];
    int add_matrix[3][3];
    printf("Matrix1:\n");
 for(int i=0;i<3;i++){
     for(int j=0;j<3;j++){
    scanf("%d",&matrix1[i][j]);


 }
 }
 printf("Matrix2:\n");
 for(int i=0;i<3;i++){
     for(int j=0;j<3;j++){
    scanf("%d",&matrix2[i][j]);
     }
     }
      printf("Sum of the poth matrix:\n");

     for(int i=0;i<3;i++){
     for(int j=0;j<3;j++){

  add_matrix[i][j]=matrix1[i][j]+matrix2[i][j];
  printf("%d ",add_matrix[i][j]);
     }
     printf("\n");
     }

    return 0;
}
