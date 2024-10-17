#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100
struct Stack {
    int items[MAX];
    int top;
};

void initializeStack(struct Stack *s);
bool isFull(const struct Stack *s);
bool isEmpty(const struct Stack *s);
void push(struct Stack *s, int value);
int pop(struct Stack *s);
int peek(const struct Stack *s);
void display(const struct Stack *s);

#endif