#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};


struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node** headRef, int value) {
    struct Node* newNode = createNode(value);

    if (*headRef != NULL) {
        newNode->next = *headRef;
        (*headRef)->prev = newNode;
    }

    *headRef = newNode;
}

// Print the list forward
void printListForward(struct Node* head) {
    struct Node* temp = head;
    printf("Doubly Linked List (Forward): ");
    while (temp != NULL) {
        printf("[%d] <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    insertAtBeginning(&head, 30);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 10);

    printListForward(head); // Should print: 10 <-> 20 <-> 30

    return 0;
}

