/*Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.*/

#include <stdio.h>
#include <stdlib.h>

/* Define Node */
typedef struct Node {
    int data;
    struct Node* next;
} Node;

/* Insert at end */
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

/* Find Intersection */
Node* findIntersection(Node* head1, Node* head2) {
    if (head1 == NULL || head2 == NULL)
        return NULL;

    Node* ptr1 = head1;
    Node* ptr2 = head2;

    while (ptr1 != ptr2) {
        ptr1 = (ptr1 == NULL) ? head2 : ptr1->next;
        ptr2 = (ptr2 == NULL) ? head1 : ptr2->next;
    }

    return ptr1;  // Either intersection node or NULL
}

int main() {
    int n, m, value;
    Node* head1 = NULL;
    Node* head2 = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head1 = insertAtEnd(head1, value);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &value);
        head2 = insertAtEnd(head2, value);
    }

    Node* intersection = findIntersection(head1, head2);

    if (intersection)
        printf("%d\n", intersection->data);
    else
        printf("No Intersection\n");

    return 0;
}