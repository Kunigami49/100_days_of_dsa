/*Implement push and pop operations on a stack and verify stack operations.*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int stack[MAX];
int top = -1;

void push(int val) {
    if (top == MAX - 1) {
        return;  // Stack Overflow (ignored as per problem)
    }
    stack[++top] = val;
}

void pop() {
    if (top == -1) {
        return;  // Stack Underflow (ignored as per problem)
    }
    top--;
}

int main() {
    int n, m;
    
    scanf("%d", &n);
    
    // Push n elements
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        push(val);
    }
    
    scanf("%d", &m);
    
    // Pop m elements
    for (int i = 0; i < m; i++) {
        pop();
    }
    
    // Print remaining stack elements from top to bottom
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    
    return 0;
}