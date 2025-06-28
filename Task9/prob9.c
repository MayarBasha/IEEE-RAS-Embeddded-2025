#include <stdio.h>
#include <stdlib.h>
#define MAX 100

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

// Check if queue is full
int isFull(struct Queue* q) {
    return q->rear == MAX - 1;
}

// Check if queue is empty
int isEmpty(struct Queue* q) {
    return q->front == -1;
}

// Enqueue operation
void enqueue(struct Queue* q, char value) {
    if (isFull(q)) {
        printf("Queue is full\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->items[++(q->rear)] = value;
    }
}

// Dequeue operation
char dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return '\0';
    } else {
        char item = q->items[q->front];
        if (q->front == q->rear) {
            q->front = q->rear = -1; // Reset queue
        } else {
            q->front++;
        }
        return item;
    }
}

int main() {
    struct Queue q;
    initialize(&q);

    // Enqueue values A, B, C
    enqueue(&q, 'A');
    enqueue(&q, 'B');
    enqueue(&q, 'C');

    // Dequeue and print one value
    char dequeuedValue = dequeue(&q);
    printf("Dequeued value: %c\n", dequeuedValue);

    return 0;
}
