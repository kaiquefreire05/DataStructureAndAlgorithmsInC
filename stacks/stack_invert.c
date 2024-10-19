#include "stack.h"

void stack_invert(struct Stack *stack) {
    struct Stack temp1;
    struct Stack temp2;
    initializeStack(&temp1);
    initializeStack(&temp2);

    if (stack == NULL || isEmpty(stack)) {
        printf("Stack is empty or not initialized.\n");
        return;
    }

    while (!isEmpty(stack)) {
        push(&temp1, pop(stack));
    }

    while (!isEmpty(&temp1)) {
        push(&temp2, pop(&temp1));
    }

    while (!isEmpty(&temp2)) {
        push(stack, pop(&temp2));
    }

}

/*
int main() {
    struct Stack s;
    initializeStack(&s);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    push(&s, 4);
    push(&s, 5);
    push(&s, 6);
    printf("Stack before inverting: \n");
    display(&s);
    stack_invert(&s);
    printf("Stack after inverting: \n");
    display(&s);
    return 0;
}
*/