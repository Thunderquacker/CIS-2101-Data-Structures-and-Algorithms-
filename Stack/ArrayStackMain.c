#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ArrayStack.h"


int main(){
	
	Stack s;
	
	init(&s);
	read(s);
	
	push(&s, 2);
	read(s);
	
	push(&s, 3);
	read(s);
	
	Element temp = top(s);
	printf("Top: %d\n", temp.data);
	
	pop(&s);
	read(s);
	
	
	
	return 0;
}
