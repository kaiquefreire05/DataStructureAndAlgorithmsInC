#include <ctype.h>
#include <string.h>

#include "stack.h"

int priorityPostfix(const char ch) {
    if (ch == '+' || ch == '-') return 1;
    if (ch == '*' || ch == '/') return 2;
    if (ch == '$') return 3;
    return 0;
}

bool isOperatorPostfix(const char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '$') return true;
    return false;
}

void postfixToPrefix(const char *postfix) {
    struct Stack s;
    initializeStack(&s);

    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isalpha(postfix[i])) {
            push(&s, postfix[i]);

        } else {
            const char op1 = pop(&s);
            const char op2 = pop(&s);
            char temp[3];
            temp[0] = postfix[i];
            temp[1] = op2;
            temp[2] = op1;
            temp[3] = '\0';
            push(&s, temp[0]);
            push(&s, temp[1]);
            push(&s, temp[2]);
        }
    }

    printf("Prefix expression: ");
    while (peek(&s) != -1) {
        printf("%c", pop(&s));
    }
}

/*
int main() {

    const char* postfix1 = "AB+C*";
    const char* postfix2 = "ABC/-AK/L-*";
    const char* postfix3 = "AB+CD-*";

    printf("Postfix expression: %s\n", postfix1);
    postfixToPrefix(postfix1);

    printf("Postfix expression: %s\n", postfix2);
    postfixToPrefix(postfix2);

    printf("Postfix expression: %s\n", postfix3);
    postfixToPrefix(postfix3);

    return 0;
}
*/