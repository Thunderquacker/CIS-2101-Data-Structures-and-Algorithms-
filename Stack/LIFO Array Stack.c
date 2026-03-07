#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 20 

typedef struct{
    char elem[MAX];
    int top;
}SA;

void init(SA *s);
bool isFull(SA s);
bool isEmpty(SA s);
void read(SA s);
void push(SA *s, int data);
void pop(SA *s);
int top(SA s);

int main(){
    
    SA s;
    
    init(&s);
    
    push(&s, 'a');
    push(&s, 'b');
    read(s);
    
    
    
    
    return 0;
}

void init(SA *s){
    s->top = -1;
}

bool isEmpty(SA s){
    return (s.top == -1) ? true : false;
}

bool isFull(SA s){
    return (s.top == MAX - 1) ? true : false;
}

void push(SA *s, int data){
    if(!isFull(*s)){
        s->elem[++(s->top)] = data;
    }
}

void pop(SA *s){
    if(!isEmpty(*s)){
        s->top--;
    }
}

void read(SA s){
    
    if(isEmpty(s)){
        printf("Stack is empty.");
        return;
    }
    
    for(int i = s.top; i >= 0; i--){
        printf("%c", s.elem[i]);
        
        if(i > 0){
            printf(", ");
        } else {
            printf(".\n");
        }
    }
}

int top(SA s){
    if(s.top >= 0){
    return s.elem[s.top];
    }
}
