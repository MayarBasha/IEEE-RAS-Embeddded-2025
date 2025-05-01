#include <stdio.h>
#include <stdlib.h>
typedef struct Cat {
    char c;
    short int s;
} cat;

// structure B
typedef struct Dog {
    short int s;
    char c;
    int i;
} dog;

int main()
{
    printf("sizeof(cat) = %lu\n", sizeof(cat));
  /*  Structure cat
The cat first element is char which is one byte aligned,
 followed by short int. short int is 2 bytes aligned.
 The compiler will insert a padding byte after the char to ensure
  short int will have an address multiple of 2.
  sizeof(char) + 1 (padding) + sizeof(short), 1 + 1 + 2 = 4 bytes.*/


    printf("sizeof(dog) = %lu\n", sizeof(dog));

    /*Structure Dog
The first member of dog is short int followed by char.
 Since char can be on any byte boundary no padding is required between short int and char,
  in total, they occupy 3 bytes. The next member is int. If the int is allocated immediately,
   it will start at an odd byte boundary. We need 1-byte padding after the char member to make
    the address of the next int member 4-byte aligned.
    the dog requires , 2 + 1 + 1 (padding) + 4 = 8 bytes.

}
