#include <stdio.h>
#include <stdlib.h>

void sortArrayAscending(int *arr, int n) {
    int *i, *j, temp;
for (i = arr; i < arr + n - 1; i++) {
    for (j = i + 1; j < arr + n; j++) {
        if (*i > *j) {
            temp = *i;
            *i = *j;
            *j = temp;
        }
    }
}
}

void sortArrayDescending(int *arr, int n) {
    int *i, *j, temp;
for (i = arr; i < arr + n - 1; i++) {
    for (j = i + 1; j < arr + n; j++) {
        if (*i < *j) {
            temp = *i;
            *i = *j;
            *j = temp;
        }
    }
}
}


int main(){
    int n;
printf("enter the number of numbers: ");
scanf("%d",&n);
int num[n];

   for (int i = 0; i < n; i++) {
        scanf("%d", num + i);  // pointer input
    }


 sortArrayAscending(num,n);

for (int i = 0; i < n; i++) {
        printf("%d ", *(num + i));  // pointer output
    }
    printf("\n");
sortArrayDescending(num,n);

    for (int i = 0; i < n; i++) {
        printf("%d ", *(num + i));  // pointer output
    }
    return 0;
}




