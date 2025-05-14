#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

int getNodeValueAtIndex(struct Node* head, int index) {
    int count = 0;
    struct Node* current = head;

    while (current != NULL) {
        if (count == index)
            return current->data;
        current = current->next;
        count++;
    }

    printf("Index %d out of bounds!\n", index);
    return -1;
}


void insertAtEnd(struct Node** headRef, int value) {
    struct Node* newNode = createNode(value);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    struct Node* temp = *headRef;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);


    int value = getNodeValueAtIndex(head, 2);
    if (value != -1)
        printf("Value at index 2: %d\n", value);

    return 0;
}

