#include <stdio.h>
#include <stdlib.h>

void mulMatrix(int *mat1,int rows1,int com, int *mat2,int cols2){

   int result[rows1][cols2];

    printf("Resultant Matrix is:\n");

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;

            for (int k = 0; k < com; k++) {
                 result[i][j] += (*(mat1 + i * com + k)) * (*(mat2 + k * cols2 + j));
            }

            printf("%d\t", result[i][j]);
        }

        printf("\n");
    }
}







int main()
{
   int rows1 ,cols1;
   int rows2 ,cols2;

   printf("enter the number of rows of first matrix: ");
   scanf("%d",&rows1);
    printf("enter the number of columns for first matrix: ");
    scanf("%d",&cols1);

     int matrix1[rows1][cols1];
     printf("enter the first matrix: \n");
     for(int i=0;i<rows1;i++){
        for(int j=0;j<cols1;j++){
            scanf("%d",&matrix1[i][j]);
        }
     }
       printf("enter the number of rows of second matrix: ");
   scanf("%d",&rows2);
    printf("enter the number of second columns: ");
    scanf("%d",&cols2);

    int matrix2[rows2][cols2];
        printf("enter the second matrix: \n");
     for(int i=0;i<rows2;i++){
        for(int j=0;j<cols2;j++){
            scanf("%d",&matrix2[i][j]);
        }
     }
   if(cols1==rows2){
    mulMatrix(matrix1,rows1,cols1,matrix2,cols2);
   }
    else{
         printf("can not mul");

         }


    return 0;
}
