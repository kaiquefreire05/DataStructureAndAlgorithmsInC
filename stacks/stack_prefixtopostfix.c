#include <ctype.h>
#include <string.h>

#include "stack.h"

int priority(const char ch) {
    if (ch == '+' || ch == '-') {
        return 1;
    }
    if (ch == '*' || ch == '/') {
        return 2;
    }
    if (ch == '$') {
        return 3;
    }
    return 0;
}

bool isOperator(const char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '$') {
        return true;
    }
    return false;
}

void prefixToPostfix(const char* prefix) {
    struct Stack s;
    initializeStack(&s);
    const int size = strlen(prefix);
    char postfix[size + 1];
    int j = 0;

    // Reverse the prefix expression
    for (int i = size - 1; i >= 0; i--) {
        const char ch = prefix[i];
        // If the character is an operand, add it to the postfix expression
        if (isalnum(ch)) {
            postfix[j++] = ch;

        } else if (isOperator(ch)) {
            // If the character is an operator, pop the operators with higher priority
            while (!isEmpty(&s) && priority(peek(&s)) > priority(ch)) {
                postfix[j++] = pop(&s);
            }
            push(&s, ch);
        }
    }

    // Pop the remaining operators
    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);
}

/*
int main() {
    const char* test1 = "+AB";
    const char* test2 = "*+AB-CD";
    const char* test3 = "$A*BC";

    printf("Prefix: %s\n", test1);
    prefixToPostfix(test1);

    printf("Prefix: %s\n", test2);
    prefixToPostfix(test2);

    printf("Prefix: %s\n", test3);
    prefixToPostfix(test3);

    return 0;
}
*/
