/*Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.*/

#include <stdio.h>
#include <stdlib.h>

/* Define Node */
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

/* Insert at end */
Node* insertAtEnd(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    // If list is empty
    if (head == NULL) {
        return newNode;
    }

    Node* temp = head;

    // Traverse to last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

/* Print Forward */
void printForward(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    Node* head = NULL;
    int value;

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insertAtEnd(head, value);
    }

    printForward(head);

    return 0;
}