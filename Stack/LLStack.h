#ifndef LLSTACK_H
#define LLSTACK_H

#include <stdbool.h>

typedef struct {
	int data;
} Element;

typedef struct node {
	Element elem;
	struct node *next;
} Node, *Stack;

void init(Stack *s);
void read(Stack s);
bool isEmpty(Stack s);
Element top(Stack s);
void pop(Stack *s);
void push(Stack *s, int data);

void free(Stack s);

#endif

