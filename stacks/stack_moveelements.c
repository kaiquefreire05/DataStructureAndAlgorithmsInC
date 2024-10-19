#include "stack.h"

void moveElements(struct Stack *s1, struct Stack *s2) {
    struct Stack temp;
    initializeStack(&temp);

    while (!isEmpty(s1)) {
        push(&temp, pop(s1));
    }

    while (!isEmpty(&temp)) {
        push(s2, pop(&temp));
    }
}

/*
int main() {
    struct Stack s1, s2;
    initializeStack(&s1);
    initializeStack(&s2);

    push(&s1, 1);
    push(&s1, 2);
    push(&s1, 3);
    push(&s1, 4);
    push(&s1, 5);
    push(&s1, 6);
    push(&s1, 7);

    printf("Printing Stack 1\n");
    display(&s1);
    moveElements(&s1, &s2);
    printf("Printing Stack 2\n");
    display(&s2);

    return 0;
}
*/