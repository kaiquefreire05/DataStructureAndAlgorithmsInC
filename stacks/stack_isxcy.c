#include <string.h>

#include "stack.h"

bool isXcy(char str[]) {
    struct Stack s;
    initializeStack(&s);
    int i = 0;
    const int size = strlen(str);

    // Check if the first half of the string is 'A's or 'B's
    while (i < size && str[i] != 'C') {
        if (str[i] != 'A' && str[i] != 'B') {
            return false;
        }
        push(&s, str[i]);
        i++;
    }

    // Check if next is 'C'
    if (i >= size || str[i] != 'C') {
        return false;
    }
    i++;

    // Check if the second half of the string
    while (i < size) {
        if (isEmpty(&s)) {
            return false;
        }
        if (str[i] != pop(&s)) {
            return false;
        }
        i++;
    }
    return isEmpty(&s);
}

/*
int main() {
    char test1[] = "ABABCBAAB";
    char test2[] = "ABABCBAA";
    char test3[] = "AABCBAA";

    printf("Result of test1: %s\n", isXcy(test1) ? "Valid" : "Invalid");
    printf("Result of test2: %s\n", isXcy(test2) ? "Valid" : "Invalid");
    printf("Result of test3: %s\n", isXcy(test3) ? "Valid" : "Invalid");
    return 0;
}
*/