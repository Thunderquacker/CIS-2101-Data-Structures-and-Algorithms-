#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 20 

typedef struct node{
    char elem;
    struct node *next;
}*SL;


void pushSL(SL *s, char data);
char popSL(SL *s);
char top(SL top);
void readSL(SL s);
int equalSL(SL s1, SL s2);

int main(){
    
    SL sA = NULL;
    SL sB = NULL;
    
    pushSL(&sA, 'c');
    pushSL(&sA, 'a');
    readSL(sA);
    
    pushSL(&sB, 'c');
    pushSL(&sB, 'a');
    readSL(sB);
    
    if(equalSL(sA, sB)){
        printf("Stacks are identical.");
    } else {
        printf("Stacks are not identical.");
    }
    
    
    
    
    
    return 0;
}



void pushSL(SL *s, char data){
    SL newNode = (SL)malloc(sizeof(struct node));
    if(newNode != NULL){
        newNode->elem = data;
        newNode->next = *s;
        *s = newNode;
        
    }
}

char popSL(SL *s){
    
    if(*s != NULL){
        SL temp = *s;
        char data = temp->elem;
        *s = (*s)->next;
        free(temp);
        return data;
    }
    return '\0';
}

void readSL(SL s){
    
    SL temp = s;
    
    while(temp != NULL){
        printf("%c", temp->elem);
        
        temp = temp->next;
        
        if(temp != NULL){
            printf(", ");
        } else {
            printf(".\n");
        }
    }
}

int equalSL(SL s1, SL s2){
    
    SL temp1 = s1;
    SL temp2 = s2;
    
    
    while(temp1 != NULL && temp2 != NULL){
        if(temp1->elem != temp2->elem){
            return 0;
        }
        
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    
    if(temp1 == NULL && temp2 == NULL){
        return 1;
    } else {
        return 0;
    }
}
