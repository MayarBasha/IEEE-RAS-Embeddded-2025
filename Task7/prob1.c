#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct student_info{

  unsigned int roll_number : 4;  // 4 bits (0-15)
    unsigned int age : 8;          // 8 bits (0-255)
    unsigned int marks : 3;         // 3 bits (0-7)
    char name[50];                 // String for name
    char address[100];             // String for address
};




/*

Bit Fields (roll_number, age, marks):

The processor will pack these bit fields together in memory

For this struct, the first 15 bits (4+8+3) will be stored in the first 2 bytes (16 bits)

The remaining bit (1 bit) in the second byte will be padding

Strings (name, address):

These are stored as contiguous blocks of memory (arrays of char)

The processor accesses them byte-by-byte

No special packing is done for these members



*/
 void print_student_info(struct student_info std[],int num){

 for(int i=0;i<num;i++){

     printf("Student %d:\n", i+1);
        printf("  Roll Number: %u\n", std[i].roll_number);
        printf("  Age: %u\n", std[i].age);
        printf("  Marks: %u\n", std[i].marks);
        printf("  Name: %s\n", std[i].name);
        printf("  Address: %s\n", std[i].address);
        printf("\n");
    }

 }





int main()
{
    struct student_info std[5]={
    {1,20,3,"mayar","zagazig"},
    {2,20,6,"aya","cairo"},
    {3,20,7,"amira","giza"},
    {4,20,4,"amal","aswan"},
    {5,20,5,"rana","alex"}
};

    print_student_info(std,5);
    printf("Size of struct student_info: %zu bytes\n", sizeof(struct student_info));
    return 0;
}
