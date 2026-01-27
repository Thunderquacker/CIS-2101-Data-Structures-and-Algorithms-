#include <stdio.h>
#include "LLStack.h"

void init(Stack *s){
	*s = NULL;
}



void read(Stack s){
	
	if(isEmpty(s)){
		printf("Stack is empty.");
		return;
	}
	
	while(!isEmpty(s)){
		printf("%d %s", s->data, (s->next != NULL) ? "->" : ".\n");
		s = s->next;
	}
}

void pop(Stack *s){
	if(!isEmpty(*S)){
		Stack temp = *s;
		*s = (*s)->next;
		free(temp);
	}
}

void push(Stack *s, int data){
	Stack newNode = (Stack)malloc(sizeof(struct node));
	
	if(newNode != NULL){
		newNode->elem.data = data;
		newNode->next = *s;
		*s = newNode;
	}
}

bool isEmpty(Stack s){
	return (s == NULL) ? true : false;
}

int top(Stack s){
	if(isEmpty(s)) return -1;
	return s->elem.data;
}

void free(Stack s){
	Stack temp;
	
	while(s != NULL){
		temp = s;
		s = s->next;
		free(temp);
	}
}

