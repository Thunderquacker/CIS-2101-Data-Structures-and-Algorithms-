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
void push(SA *s, char data);
char pop(SA *s);
int top(SA s);
int equal(SA s1, SA s2);

int main(){
    
    SA s;
    
    init(&s);
    
    printf("Pushing: ");
    push(&s, 'a');
    push(&s, 'b');
    read(s);
    
    printf("Popped: ");
    pop(&s);
    read(s);
    
    
    
    return 0;
}

void init(SA *s){
    s->top = MAX;
}

bool isEmpty(SA s){
    return (s.top == MAX) ? true : false;
}

bool isFull(SA s){
    return (s.top == 0) ? true : false;
}

void push(SA *s, char data){
    if(!isFull(*s)){
        s->elem[--(s->top)] = data;
    }
}

char pop(SA *s){
    if(!isEmpty(*s)){
        return s->elem[(s->top)++];
    }
}

int equal(SA s1, SA s2){
    
    if(s1.top != s2.top){
        return 0;
    }
    
    for(int i = 0; i < s1.top; i++){
        if(s1.elem[i] != s2.elem[i]){
            return 0;
        }
    }
    
    return 1;
}

void read(SA s){
    
    if(isEmpty(s)){
        printf("Stack is empty.");
        return;
    }
    
    for(int i = s.top; i < MAX; i++){
        printf("%c", s.elem[i]);
        
        if(i < MAX - 1){
            printf(", ");
        } else {
            printf(".\n");
        }
    }
}

int top(SA s){
    if(s.top < MAX){
    return s.elem[s.top];
    }
}
