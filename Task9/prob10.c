#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 3 // Small size to demonstrate full condition

struct Queue {
    char items[MAX];
    int front;
    int rear;
};

// Initialize queue
void initialize(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Check if queue is empty
bool isEmpty(struct Queue* q) {
    return q->front == -1;
}

// Check if queue is full
bool isFull(struct Queue* q) {
    return (q->rear + 1) % MAX == q->front;
}

// Enqueue operation
void enqueue(struct Queue* q, char value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue %c.\n", value);
        return;
    }

    if (isEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX;
    }

    q->items[q->rear] = value;
    printf("Enqueued: %c\n", value);
}

// Dequeue operation
char dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return '\0';
    }

    char item = q->items[q->front];

    if (q->front == q->rear) {
        q->front = q->rear = -1; // Queue becomes empty
    } else {
        q->front = (q->front + 1) % MAX;
    }

    printf("Dequeued: %c\n", item);
    return item;
}

// Get front value
char getFront(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. No front value.\n");
        return '\0';
    }
    return q->items[q->front];
}

// Get rear value
char getRear(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. No rear value.\n");
        return '\0';
    }
    return q->items[q->rear];
}

// Print queue status
void printStatus(struct Queue* q) {
    printf("\nQueue Status:\n");
    printf("------------\n");
    printf("Empty: %s\n", isEmpty(q) ? "Yes" : "No");
    printf("Full: %s\n", isFull(q) ? "Yes" : "No");

    if (!isEmpty(q)) {
        printf("Front: %c\n", getFront(q));
        printf("Rear: %c\n", getRear(q));
    }

    printf("Contents: ");
    if (isEmpty(q)) {
        printf("Empty");
    } else {
        int i = q->front;
        while (1) {
            printf("%c ", q->items[i]);
            if (i == q->rear) break;
            i = (i + 1) % MAX;
        }
    }
    printf("\n------------\n\n");
}

int main() {
    struct Queue q;
    initialize(&q);

    // Initial status
    printf("Initial queue:\n");
    printStatus(&q);

    // Enqueue A, B, C
    enqueue(&q, 'A');
    enqueue(&q, 'B');
    enqueue(&q, 'C');
    printStatus(&q);

    // Try to enqueue when full
    enqueue(&q, 'D');

    // Check front and rear
    printf("Front value: %c\n", getFront(&q));
    printf("Rear value: %c\n", getRear(&q));

    // Dequeue one item
    dequeue(&q);
    printStatus(&q);

    // Enqueue again to test circular behavior
    enqueue(&q, 'E');
    printStatus(&q);

    return 0;
}
