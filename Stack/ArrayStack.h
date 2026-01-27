#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H
#define MAX 10

typedef struct {
	int data;
} Element;

typedef struct {
	Element Elements[MAX];
	int top;
} Stack;

void init(Stack *s);
void read(Stack s);
bool isEmpty(Stack s);
bool isFull(Stack s);
Element top(Stack s);
void pop(Stack *s);
void push(Stack *s, int data);


#endif


