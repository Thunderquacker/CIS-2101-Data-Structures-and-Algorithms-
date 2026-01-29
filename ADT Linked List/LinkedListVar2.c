#include <stdio.h>
#include <stdlib.h>
#include "LinkedListVar1.h"

List init(){
    List L;
    L.head = NULL;
    L.count = 0;
    return L;
}

void empty(List *L){
    Node *curr = L->head;
    while(curr != NULL){
        Node *temp = curr;
        curr = curr->next;
        free(temp);
    }
    
    L->head = NULL;
    L->count = 0;
    
}

void insertFirst(List *L, int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    
    if(newNode == NULL) return;
    
    newNode->data = data;
    newNode->next = NULL;
    
    if(L->head == NULL){
        L->head == newNode;
    } else {
        Node *curr = L->head;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = newNode;
    }
    L->count++;
}

void insertLast(List *L, int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    
    if(newNode == NULL) return;
    
    newNode->data = data;
    newNode->next = NULL;
    
    if(L->head == NULL){
        L->head = newNode;
    } else {
        Node *curr = L->head;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = newNode;
    }
    L->count++;
}

void insertPos(List *L, int data, int index){
    if(index < 0 || index > L->count) return;
    
    if(index == 0){
        insertFirst(L, data);
    } else {
        Node *newNode = (Node*)malloc(sizeof(Node));
        Node *curr = L->head;
        for(int i = 0; i < index - 1; i++){
            curr = curr->next;
        }
        newNode->data = data;
        newNode->next = curr->next;
        curr->next = newNode;
        L->count++;
    }
}

void deleteStart(List *L){
    if(L->head != NULL){
        Node *temp = L->head;
        L->head = L->head->next;
        free(temp);
        L->count--;
    }
}

void deleteLast(List *L){
    if(L->head == NULL) return;
    
    if(L->head->next == NULL){
        free(L->head);
        L->head = NULL;
    } else {
        Node *curr = L->head;
        while(curr->next->next != NULL){
            curr = curr->next;
        }
        free(curr->next);
        curr->next = NULL;
    }
    L->count--;
}

void display(List *L){
    Node *curr = L->head;
    
    printf("[%d elements]: ", L->count);
    while(curr != NULL){
        printf("%d ->", curr->data);
        curr = curr->next;
    }
}
