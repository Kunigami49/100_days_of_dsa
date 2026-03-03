/*Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.
*/

#include <stdio.h>
#include <stdlib.h>

/* Define Node */
typedef struct Node {
    int coeff;
    int exp;
    struct Node* next;
} Node;

/* Insert at End */
Node* insertTerm(Node* head, int coeff, int exp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

/* Print Polynomial */
void printPolynomial(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        if (temp->exp == 0)
            printf("%d", temp->coeff);
        else if (temp->exp == 1)
            printf("%dx", temp->coeff);
        else
            printf("%dx^%d", temp->coeff, temp->exp);

        if (temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }
}

int main() {
    int n, coeff, exp;
    Node* head = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        head = insertTerm(head, coeff, exp);
    }

    printPolynomial(head);

    return 0;
}