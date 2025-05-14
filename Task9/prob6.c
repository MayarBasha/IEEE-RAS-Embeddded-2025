#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtPosition(struct Node** headRef, int value, int position) {
    struct Node* newNode = createNode(value);

    // Case: Empty list
    if (*headRef == NULL) {
        newNode->next = newNode;
        *headRef = newNode;
        return;
    }

    // Insert at head (position 0)
    if (position == 0) {
        struct Node* temp = *headRef;
        while (temp->next != *headRef) {
            temp = temp->next;
        }

        newNode->next = *headRef;
        temp->next = newNode;
        *headRef = newNode;
        return;
    }

    struct Node* current = *headRef;
    for (int i = 0; i < position - 1; i++) {
        current = current->next;
        if (current == *headRef) {
            printf("Position out of bounds.\n");
            return;
        }
    }

    newNode->next = current->next;
    current->next = newNode;
}

void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular List: ");
    do {
        printf("[%d] -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("back to head\n");
}

int main() {
    struct Node* head = NULL;

    insertAtPosition(&head, 10, 0);  // Insert at head
    insertAtPosition(&head, 20, 1);  // Insert at position 1
    insertAtPosition(&head, 30, 2);  // Insert at position 2
    insertAtPosition(&head, 5, 0);   // Insert at head again
    insertAtPosition(&head, 25, 2);  // Insert at position 2

    printList(head);

    return 0;
}

