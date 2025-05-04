#include <stdio.h>

enum days {
    Saturday,  // 0
    Sunday  ,   // 1
    Monday,    // 2
    Tuesday,   // 3
    Wednesday, // 4
    Thursday,  // 5
    Friday   // 6


};
int check(enum days D){
if(D==1||D==2||D==3||D==4||D==5){
    return 1;
}
else{
    return 0;
}
}
int main (){
enum days day =Sunday;

if(check(day)){
 printf("it's a weekday ");
}
else{
    printf("it's a weekend");
}




}
