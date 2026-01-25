#include <stdio.h>
#include <stdlib.h>
#include "LLStack.h"

int main(){
	
	Stack s;
	init(&s);
	
	push(&s, 10);
	push(&s, 11);
	read(s);
	
	printf("Top element: %d\n", top(s));
	
	pop(&s);
	read(s);
	
	
	
	
	return 0;
}


