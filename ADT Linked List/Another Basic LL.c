#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}LIST, *ctrlink;

ctrlink createNode(int value);
void insertFront(LIST **L, int data);
void insertRear(LIST **L, int data);
void insertPos(LIST **L, int data, int pos);
void deleteFront(LIST **L);
void deleteRear(LIST **L);
void deletePos(LIST **L, int pos);
void display(LIST *L);

int main(){
    
   ctrlink head = NULL;
   
   insertFront(&head, 10);
   insertRear(&head, 20);
   insertPos(&head, 15, 0);
   insertPos(&head, 45, 3);
   
   display(head);
   
   printf("\nDeletion: ");
   deleteFront(&head);
   deleteRear(&head);
   deletePos(&head, 0);
   
   display(head);
    
    
    
    return 0;
}

ctrlink createNode(int value){
    ctrlink newNode = (ctrlink)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertFront(LIST **L, int data){
    ctrlink newNode = createNode(data);
    newNode->next = *L;
    *L = newNode;
}

void insertRear(LIST **L, int data){
    ctrlink newNode = createNode(data);
    
    if(*L == NULL){
        *L = newNode;
        return;
    }
    
    ctrlink temp = *L;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertPos(LIST **L, int data, int pos){
    if(pos == 0){
        insertFront(L, data);
        return;
    }
    
    ctrlink newNode = createNode(data);
    ctrlink temp = *L;
    
    for(int i = 0; temp != NULL && i < pos - 1; i++){
        temp = temp->next;
    }
    
    if(temp == NULL){
        printf("Position out of bounds.");
        free(newNode);
        return;
    }
    
    newNode->next = temp->next;
    temp->next = newNode;
}

void display(LIST *L){
    
    while(L != NULL){
        printf("%d->", L->data);
        L = L->next;
    }
    printf("NULL");
}

void deleteFront(LIST **L){
    ctrlink temp = *L;
    *L = (*L)->next;
    free(temp);
}

void deleteRear(LIST **L){
    if((*L)->next == NULL){
        free(*L);
        *L = NULL;
        return;
    }
    
    ctrlink temp = *L;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    
    free(temp->next);
    temp->next = NULL;
}

void deletePos(LIST **L, int pos){
    if(pos == 0){
        deleteFront(L);
        return;
    }
    
    ctrlink temp = *L;
    for(int i = 0; temp != NULL && i < pos - 1; i++){
        temp = temp->next;
    }
    
    if(temp == NULL || temp->next == NULL) return;
    
    ctrlink nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
}




