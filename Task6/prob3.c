#include <stdio.h>


struct Animal {
    char name[50];
    int age;
    char kind[20];
};


struct Animal createAnimal(const char* name, int age, const char* kind) {
    struct Animal a;

    // Copy name and kind (assumes inputs are short enough)
    snprintf(a.name, sizeof(a.name), "%s", name);
    a.age = age;
    snprintf(a.kind, sizeof(a.kind), "%s", kind);

    return a;
}

void printAnimal(struct Animal a) {
    printf("Name: %s\n", a.name);
    printf("Age: %d\n", a.age);
    printf("Kind: %s\n", a.kind);
}


int main() {
    struct Animal dog = createAnimal("zeko", 4, "Dog");


    printAnimal(dog);


    return 0;
}
