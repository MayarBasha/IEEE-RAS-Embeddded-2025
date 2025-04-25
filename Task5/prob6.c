
 #include <stdio.h>

int add(int a, int b) {
    return a + b;
    }
int sub(int a, int b) {
    return a - b;
    }

int mul(int a, int b) {
    return a * b;
    }
 int div(int a, int b) {
    return a / b;
    }


int main() {
  int choice,num1,num2;
	// Declaring function pointer
	int (*fptr)(int, int);

  printf("eslect an operation:\n 1.add\n 2.subtraction\n 3.multiplication\n 4.division\n");

  printf("enter your choice: ");
  scanf("%d",&choice);

  printf("enter two numbers: ");
  scanf("%d %d",&num1,&num2);

  	// Assigning address of add() functoin to fptr
  	switch(choice){
  	    case 1:
  	     fptr = &add;
         break;
        case 2:
          fptr = &sub;
          break;
        case 3:
            fptr = &mul;
            break;
        case 4:
            fptr = &div;
            break;
            }
	// Calling function using function pointer
	int res = fptr(num1, num2);

	printf("%d", res);
	return 0;
}

