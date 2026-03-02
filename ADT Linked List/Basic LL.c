#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef struct node{
    int data;
    struct node *next;
}LIST, *ctrlink;

ctrlink createNode(int value);
void insertFront(ctrlink *head, int value);
void insertRear(ctrlink *head, int value);
void deleteFront(ctrlink *head);
void deleteRear(ctrlink *head);
void deleteAt(ctrlink *head, int pos);
void insertAt(ctrlink *head, int pos, int value);
void display(ctrlink head);



int main(){
    
    ctrlink head = NULL;
    
    insertFront(&head, 1);
    insertRear(&head, 2);
    insertAt(&head, 0, 300);
    display(head);
    
    
    return 0;
}

ctrlink createNode(int value){
    ctrlink newNode = (ctrlink)malloc(sizeof(LIST));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertFront(ctrlink *head, int value){
    
    ctrlink newNode = createNode(value);
    
    newNode->next = *head;
    *head = newNode;
}

void insertRear(ctrlink *head, int value){
    
    ctrlink newNode = createNode(value);
    
    if(*head== NULL){
        *head = newNode;
        return;
    }
    
    ctrlink temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteFront(ctrlink *head){
    
    if(*head == NULL) return;
    
    ctrlink temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteRear(ctrlink *head){
    
    if(*head == NULL) return;
    
    if((*head)->next == NULL){
        free(*head);
        *head = NULL;
        return;
    }
    
    ctrlink temp = *head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    
}

void deleteAt(ctrlink *head, int pos){
    
    if(*head == NULL) return;
    if(pos == 0){
        deleteFront(head);
        return;
    }
    
    ctrlink temp = *head;
    for(int i = 0; temp != NULL && i < pos - 1; i++){
        temp = temp->next;
    }
    
    if(temp == NULL || temp->next == NULL) return;
    
    ctrlink Node = temp->next;
    temp->next = Node->next;
    free(Node);
}

void insertAt(ctrlink *head, int pos, int value){
 
    if(pos == 0){
        insertFront(head, value);
        return;
    }   
    
    ctrlink newNode = createNode(value);
    ctrlink temp = *head;
    
    for(int i = 0; temp != NULL && i < pos - 1; i++){
        temp = temp->next;
    }
    
    if(temp == NULL){
        printf("Invalid position");
        return;
    }
    
    newNode->next = temp->next;
    temp->next = newNode;
}

void display(ctrlink head){
    
    ctrlink temp = head;
    
    while(temp != NULL){
        printf("%d", temp->data);
        
        if(temp->next != NULL){
            printf("->");
        }
        temp = temp->next;
    }
    
    printf("->NULL");
    
}

