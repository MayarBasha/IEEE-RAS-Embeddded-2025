#include <stdio.h>
#include <stdlib.h>

// Define the structure
struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert at the end
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

// Insert at the beginning
void insertAtBeginning(struct Node** headRef, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = *headRef;
    *headRef = newNode;
}

// Delete a node by value
void deleteNode(struct Node** headRef, int value) {
    struct Node* temp = *headRef;
    struct Node* prev = NULL;

    // If head node is the one to delete
    if (temp != NULL && temp->data == value) {
        *headRef = temp->next;
        free(temp);
        return;
    }

    // Search for the node to delete
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with value %d not found!\n", value);
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Print list and length
void printListAndLength(struct Node* head) {
    int length = 0;
    struct Node* current = head;

    printf("  ");
    while (current != NULL) {
        printf("[%d] -> ", current->data);
        current = current->next;
        length++;
    }
    printf("NULL\n");

    printf("Total cars: %d\n", length);
}


int main() {
    struct Node* head = NULL;

    // Inserting at the end
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    // Inserting at the beginning
    insertAtBeginning(&head, 5);

    // Printing list
    printListAndLength(head);

    // Deleting a node
    deleteNode(&head, 20);
    printListAndLength(head);

    return 0;
}

