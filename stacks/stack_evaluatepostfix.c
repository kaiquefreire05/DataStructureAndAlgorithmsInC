#include <ctype.h>
#include <math.h>
#include <stdlib.h>

#include "stack.h"

int evaluatePostFix(char exp[], const int A, const int B, const int C) {
    struct Stack s;
    initializeStack(&s);

    for (int i = 0; exp[i] != '\0'; i++) {
        const char ch = exp[i];
        if (isalpha(ch)) {
            int value = 0;
            if (ch == 'A') value = A;
            else if (ch == 'B') value = B;
            else if (ch == 'C') value = C;
            push(&s, value);

        } else {
            if (isEmpty(&s)) {
                printf("Invalid expression\n");
                exit(1);
            }
            const int val2 = pop(&s);
            if (isEmpty(&s)) {
                printf("Invalid expression\n");
                exit(1);
            }
            const int val1 = pop(&s);

            switch(ch) {
                case '+':
                    push(&s, val1 + val2);
                    break;
                case '-':
                    push(&s, val1 - val2);
                    break;
                case '*':
                    push(&s, val1 * val2);
                    break;
                case '/':
                    if (val2 == 0) {
                        printf("Division by zero error\n");\
                        exit(1);
                    }
                    push(&s, val1 / val2);
                    break;
                case '$':
                    push(&s, pow(val1, val2));
                    break;
                default:
                    printf("Unknown operator: %c\n", ch);
                    exit(1);
            }
        }
    }
    if (!isEmpty(&s)) {
        const int result = pop(&s);
        if (!isEmpty(&s)) {
            printf("Invalid expression - too many operands\n");
            exit(1);
        }
        return result;
    } else {
        printf("Invalid expression - no result found\n");
        exit(1);
    }
}

/*
int main() {
    const int A = 1, B = 2, C = 3;

    char expression1[] = "AB-C+";
    char expression2[] = "ABC++";
    char expression3[] = "AB+C-CA+/";

    const int result1 = evaluatePostFix(expression1, A, B, C);
    const int result2 = evaluatePostFix(expression2, A, B, C);
    const int result3 = evaluatePostFix(expression3, A, B, C);

    printf("Result of expression 1: %d\n", result1);
    printf("Result of expression 2: %d\n", result2);
    printf("Result of expression 3: %d\n", result3);

    return 0;
}
*/