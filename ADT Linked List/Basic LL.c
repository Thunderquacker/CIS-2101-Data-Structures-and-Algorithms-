// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}*List;

List createNode(int data);
void insertFirst(List *L, int data);
void insertRear(List *L, int data);
void insertAt(List *L, int data, int pos);
void deleteFirst(List *L);
void deleteRear(List *L);
void deleteAt(List *L, int pos);
void display(List L);

int main() {
    
    List L = NULL;
    
    insertFirst(&L, 10);
    insertFirst(&L, 20);
    insertRear(&L, 50);
    insertRear(&L, 5);
    insertAt(&L, 100, 0);
    
    display(L);
    
    printf("\nAfter deletion: ");
    deleteFirst(&L);
    deleteRear(&L);
    deleteAt(&L, 0);
    display(L);

    return 0;
}

List createNode(int data){
    List newNode = (List)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertFirst(List *L, int data){
    
    List newNode = createNode(data);
    
    newNode->next = *L;
    *L = newNode;
}

void insertRear(List *L, int data){
    
    List newNode = createNode(data);
    
    if(newNode == NULL){
        *L = newNode;
        return;
    }
    
    List temp = *L;
    
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteFirst(List *L){
    
    List temp = *L;
    *L = (*L)->next;
    free(temp);
}

void deleteRear(List *L){
    
    if(*L == NULL) return;
    
    if((*L)->next == NULL){
        free(*L);
        *L = NULL;
        return;
    }
    
    List temp = *L;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void deleteAt(List *L, int pos){
    
    if(*L == NULL) return;
    
    if(pos == 0){
        deleteFirst(L);
        return;
    }
    
    List temp = *L;
    for(int i = 0; temp->next != NULL && i < pos - 1; i++){
        temp = temp->next;
    }
    
    List Node = temp->next;
    temp->next = Node->next;
    free(Node);
}

void insertAt(List *L, int data, int pos){
    
    if(pos == 0){
        insertFirst(L, data);
        return;
    }
    
    List newNode = createNode(data);
    List temp = *L;
    
    for(int i = 0; temp != NULL && i < pos - 1; i++){
        temp = temp->next;
    }
    
    newNode->next = temp->next;
    temp->next = newNode;
}

void display(List L){
    
    List temp = L;
    while(temp != NULL){
        printf("%d", temp->data);
        if(temp->next != NULL){
            printf("->");
        }
        temp = temp->next;
    }
    printf("->NULL\n");
}
