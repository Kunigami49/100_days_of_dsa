/*Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    
    struct Node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    
    return val;
}

int evaluatePostfix(char* exp) {

    for (int i = 0; exp[i] != '\0'; i++) {

        if (isdigit(exp[i])) {
            push(exp[i] - '0');
        }

        else {
            int val2 = pop();
            int val1 = pop();

            switch (exp[i]) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
            }
        }
    }

    return pop();
}

int main() {
    char exp[100];

    printf("Enter postfix expression: ");
    scanf("%s", exp);

    int result = evaluatePostfix(exp);

    printf("%d", result);

    return 0;
}