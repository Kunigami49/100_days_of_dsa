/*Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.*/

#include <stdio.h>
#include <stdlib.h>

/* Define Node */
typedef struct Node {
    int data;
    struct Node* next;
} Node;

/* Insert at End */
Node* insertAtEnd(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

/* Rotate Right by k */
Node* rotateRight(Node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    Node* temp = head;
    int len = 1;

    // Find length and last node
    while (temp->next != NULL) {
        temp = temp->next;
        len++;
    }

    // Make it circular
    temp->next = head;

    k = k % len;
    int stepsToNewTail = len - k;

    Node* newTail = head;

    for (int i = 1; i < stepsToNewTail; i++) {
        newTail = newTail->next;
    }

    Node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

/* Print List */
void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, k, value;
    Node* head = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insertAtEnd(head, value);
    }

    scanf("%d", &k);

    head = rotateRight(head, k);

    printList(head);

    return 0;
}