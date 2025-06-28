#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Stack {
    int top;
    int items[MAX];
};

void push(struct Stack* s, int value) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        s->items[++(s->top)] = value;
    }
}

int pop(struct Stack* s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return s->items[(s->top)--];
    }
}

int main() {
    struct Stack s;
    s.top = -1; // Initialize empty stack

    // Pushing values
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    // Popping and printing the top value
    int poppedValue = pop(&s);
    printf("Popped value: %d\n", poppedValue);

    return 0;
}
