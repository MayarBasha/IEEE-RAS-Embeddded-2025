#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Stack {
    int top;
    int items[MAX];
};




// Check if stack is full
int isFull(struct Stack* s) {
    return s->top == MAX - 1;
}

// Check if stack is empty
int isEmpty(struct Stack* s) {
    return s->top == -1;
}

// Push element onto stack
void push(struct Stack* s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
    } else {
        s->items[++(s->top)] = value;
    }
}

// Pop element from stack
int pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return s->items[(s->top)--];
    }
}

// Peek at top element without popping
int peek(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->items[s->top];
}

// Print stack contents
void printStack(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack (top to bottom): ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}

// Swap top two elements
void swapTopTwo(struct Stack* s) {
    if (s->top < 1) {
        printf("Not enough elements to swap\n");
        return;
    }

    int top = pop(s);
    int second = pop(s);

    push(s, top);
    push(s, second);
}

int main() {
    struct Stack s;

    s.top = -1;

    // Push values onto stack
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    // Print stack before swap
    printf("Before swap:\n");
    printStack(&s);

    // Swap top two elements
    swapTopTwo(&s);

    // Print stack after swap
    printf("\nAfter swap:\n");
    printStack(&s);

    return 0;
}
