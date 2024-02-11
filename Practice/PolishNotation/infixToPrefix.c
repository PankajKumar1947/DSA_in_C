#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Function to check if the given character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to return the precedence of the operator
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Function to reverse a string
void reverseString(char* str) {
    int length = strlen(str);
    for (int i = 0, j = length - 1; i < j; ++i, --j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to convert infix expression to prefix expression
void infixToPrefix(const char* infix, char* prefix) {
    char stack[MAX_SIZE];
    int top = -1;

    // Reverse the infix expression
    char reversedInfix[MAX_SIZE];
    strcpy(reversedInfix, infix);
    reverseString(reversedInfix);

    // Process the reversed infix expression
    for (int i = 0, j = 0; reversedInfix[i]; ++i) {
        if (isalnum(reversedInfix[i])) {
            prefix[j++] = reversedInfix[i];
        } else if (reversedInfix[i] == ')') {
            stack[++top] = reversedInfix[i];
        } else if (reversedInfix[i] == '(') {
            while (top != -1 && stack[top] != ')') {
                prefix[j++] = stack[top--];
            }
            --top; // Discard the ')'
        } else { // Operator
            while (top != -1 && precedence(reversedInfix[i]) < precedence(stack[top])) {
                prefix[j++] = stack[top--];
            }
            stack[++top] = reversedInfix[i];
        }
    }

    while (top != -1) {
        prefix[strlen(prefix)] = stack[top--];
    }

    // Reverse the prefix expression to get the final result
    reverseString(prefix);
}

int main() {
    char infix[MAX_SIZE], prefix[MAX_SIZE];

    printf("Enter infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    
    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);
    return 0;
}
