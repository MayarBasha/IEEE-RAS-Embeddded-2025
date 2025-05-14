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


void freeList(struct Node** headRef) {
    struct Node* current = *headRef;
    struct Node* nextNode;

    while (current != NULL) {
        nextNode = current->next; // Save next node
        free(current);            // Free current node
        current = nextNode;       // Move to next
    }

    *headRef = NULL; // Set head to NULL after deletion
}


// Print list and length
void printListAndLength(struct Node* head) {
    int length = 0;
    struct Node* current = head;

    printf("linkedList: ");
    while (current != NULL) {
        printf("[%d] -> ", current->data);
        current = current->next;
        length++;
    }
    printf("NULL\n");

    printf("Total : %d\n", length);
}

// Main to test
int main() {
    struct Node* head = NULL;

    // Inserting at the end
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);



    // Printing list
    printListAndLength(head);

    // Deleting a node
   freeList(&head);
    printListAndLength(head);

    return 0;
}
