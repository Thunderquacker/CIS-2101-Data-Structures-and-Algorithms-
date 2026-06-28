#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[50];
    char color[50];
    char type[50];
}Cat;

typedef struct node{
    Cat cat;
    struct node *next;
}*List;

List createNode(Cat newCat);
void insertFirst(List *L, Cat c);
void insertSorted(List *L, Cat c);
void insertLast(List *L, Cat c);
void insertPos(List *L, Cat c, int pos);
void deletePos(List *L, int pos);
void display(List L);
void deleteFirst(List *L);
void deleteLast(List *L);

int main(){
    
    List L = NULL;
    
    Cat c1 = {"Tyler", "Blue", "Siamese"};
    Cat c2 = {"Rick", "Purple", "Yes"};
    
    insertFirst(&L, c1);
    insertPos(&L, c2, 0);
    display(L);
    
    printf("\nAfter deleting: ");
    deletePos(&L, 0);
    display(L);
    
    return 0;
}


List createNode(Cat newCat){
    List c = (List)malloc(sizeof(struct node));
    if(c != NULL){
    c->cat = newCat;
    c->next = NULL;
    }
    return c;
}

void insertFirst(List *L, Cat c){
    
    List newNode = createNode(c);
    
    if(newNode != NULL){
        newNode->next = *L;
        *L = newNode;
    }
}

void insertLast(List *L, Cat c){
    
    List newNode = createNode(c);
    
    if(newNode != NULL){
        *L = newNode;
        return;
    }
    
    List temp = *L;
    
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertPos(List *L, Cat c, int pos){
    
    List newNode = createNode(c);
    
    if(pos == 0){
        insertFirst(L, c);
        return;
    }
    
    List temp = *L;
    
    for(int i = 0; temp != NULL && i < pos - 1; i++){
        temp = temp->next;
    }
    if(temp == NULL){
        printf("Position out of bound.");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertSorted(List *L, Cat c){
    
    List newNode = createNode(c);
    
    if(*L == NULL){
        newNode->next = *L;
        *L = newNode;
        return;
    }
    
    List temp = *L;
    while(temp->next != NULL && strcmp(temp->next->cat.name, c.name) == 0){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void display(List L){
    
    List temp = L;
    
    while(temp != NULL){
        printf("%s %s %s\n", temp->cat.name, temp->cat.color, temp->cat.type);
        temp = temp->next;
    }
}

void deleteFirst(List *L){
    
    List temp = *L;
    (*L) = (*L)->next;
    free(temp);
}

void deleteLast(List *L){
    
    if((*L)->next == NULL){
        (*L) = (*L)->next;
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

void deletePos(List *L, int pos){
    
    if(pos == 0){
        deleteFirst(L);
        return;
    }
    
    List temp = *L;
    
    for(int i = 0; temp != NULL && i < pos - 1; i++){
        temp = temp->next;
    }
    
    List node = temp->next;
    temp->next = node;
    free(node);
}
