#include <stdio.h>
#include <stdlib.h>
struct variable{
int num;

};
void initialize(struct variable* A ){
A->num=10;

}
void print(struct variable A){
printf("num = %d",A.num);
}
int main()
{
    struct variable var;
initialize(&var);
   print(var);
    return 0;
}
