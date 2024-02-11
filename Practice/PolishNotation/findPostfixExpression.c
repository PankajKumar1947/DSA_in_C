#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

// Structure to represent a stack
struct Stack {
    int top;
    int array[MAX_SIZE];
};

// Function to check if the given character is a digit
int isDigit(char ch) {
    return (ch >= '0' && ch <= '9');
}

// Function to create a stack
void initializeStack(struct Stack* stack) {
    stack->top = -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack->array[++stack->top] = item;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack->array[stack->top--];
}

// Function to evaluate postfix expression
int evaluatePostfix(const char* postfix) {
    struct Stack stack;
    initializeStack(&stack);

    for (int i = 0; postfix[i]; ++i) {
        if (isDigit(postfix[i])) {
            push(&stack, postfix[i] - '0'); // Convert character digit to integer
        } else {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            switch (postfix[i]) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
            }
        }
    }
    return pop(&stack);
}

int main() {
    char postfix[MAX_SIZE];

    printf("Enter postfix expression: ");
    fgets(postfix, sizeof(postfix), stdin);
    
    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);
    return 0;
}
