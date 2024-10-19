#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "stack.h"

bool isEquals(const char open, const char close) {
    if (open == '(' && close == ')') return true;
    if (open == '{' && close == '}') return true;
    if (open == '[' && close == ']') return true;
    return false;
}

bool isBalanced(const char text[]) {
    struct Stack s;
    initializeStack(&s);
    const int size = strlen(text);
    for (int i = 0; i < size; i++) {
        const char current = text[i];
        if (current == '(' || current == '{' || current == '[') {
            push(&s, current);
        } else if (current == ')' || current == '}' || current == ']') {
            if (isEmpty(&s)) {
                return false;
            }
            const char open = pop(&s);
            if (!isEquals(open, current)) {
                return false;
            }
        }
    }
    return isEmpty(&s);
}

/*
int main() {
    const char test1[] = "{[()]}"; // Balanced
    const char test2[] = "{[(])}"; // Not balanced
    const char test3[] = "{[()]abc}"; // Balanced
    const char test4[] = "{[()"; // Not balanced
    const char test5[] = ""; // Balanced
    const char test6[] = ")}]"; // Not balanced
    const char test7[] = "{{[[(())]]}}"; // Balanced

    printf("Test 1: %s\n", isBalanced(test1) ? "Balanced" : "Not balanced");
    printf("Test 2: %s\n", isBalanced(test2) ? "Balanced" : "Not balanced");
    printf("Test 3: %s\n", isBalanced(test3) ? "Balanced" : "Not balanced");
    printf("Test 4: %s\n", isBalanced(test4) ? "Balanced" : "Not balanced");
    printf("Test 5: %s\n", isBalanced(test5) ? "Balanced" : "Not balanced");
    printf("Test 6: %s\n", isBalanced(test6) ? "Balanced" : "Not balanced");
    printf("Test 7: %s\n", isBalanced(test7) ? "Balanced" : "Not balanced");

    return 0;
}
*/