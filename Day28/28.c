/*Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.*/

#include <stdio.h>
#include <stdlib.h>

/* Define Node */
typedef struct Node {
    int data;
    struct Node* next;
} Node;

/* Insert at End in Circular Linked List */
Node* insertAtEnd(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;

    // If list is empty
    if (head == NULL) {
        newNode->next = newNode;  // Point to itself
        return newNode;
    }

    Node* temp = head;

    // Traverse till last node
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;

    return head;
}

/* Print Circular Linked List */
void printCircular(Node* head) {
    if (head == NULL)
        return;

    Node* temp = head;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

int main() {
    int n, value;
    Node* head = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insertAtEnd(head, value);
    }

    printCircular(head);

    return 0;
}