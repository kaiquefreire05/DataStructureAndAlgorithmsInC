#include "stack.h"

void initializeStack(struct Stack *s) {
    s->top = -1;  // Empty stack
}

bool isFull(const struct Stack *s) {
    return s->top == MAX - 1;
}

bool isEmpty(const struct Stack *s) {
    return s->top == -1;
}

void push(struct Stack *s, const int value) {
    if (isFull(s)) {
        printf("Stack is full\n");
    } else {
        s->top++;
        s->items[s->top] = value;
    }
}

int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    const int value = s->items[s->top];
    s->top--;
    return value;
}

int peek(const struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->items[s->top];
}

void display(const struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = s->top; i >= 0; i--) {
        printf("%d\n", s->items[i]);
    }
    printf("\n");
}
