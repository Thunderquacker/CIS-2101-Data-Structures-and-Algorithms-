#include <stdio.h>
#include <stdbool.h>
#include "ArrayStack.h"

void init(Stack *S){
	S->top = -1;
}

void read(Stack s){
	printf("Stack: ");
	if(isEmpty(s)){
		printf("Stack is empty.");
	}
	
	while(!isEmpty(s)){
		Element T = top(s);
		printf("%d", T.data);
		pop(&s);
		printf("%s", (!isEmpty(s)) ? "," : ".\n");
	}
}

bool isEmpty(Stack s){
	return (s.top == -1) ? true : false;
}

bool isFull(Stack s){
	return (s.top == MAX - 1) ? true : false;
}

Element top(Stack s){
	Element d = {-1};
	return (!isEmpty(s)) ? s.Elements[s.top] : d;
}

void pop(Stack *s){
	if(!isEmpty(*s)){
		s->top--;
	}
}

void push(Stack *s, int data){
	if(!isFull(*s)){
		s->Elements[++s->top].data = data;
	}
}
