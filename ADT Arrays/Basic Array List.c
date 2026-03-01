#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef struct{
    int elem[MAX];
    int count;
}LIST;

void init(LIST *L);
void display(LIST *L);
void insertFront(LIST *L, int data);
void insertRear(LIST *L, int data);
void insertpos(LIST *L, int data, int pos);
void deleteRear(LIST *L);
void deleteFront(LIST *L);
void deletepos(LIST *L, int pos);


int main(){
    
    LIST L;
    
    init(&L);
    insertFront(&L, 10);
    insertpos(&L, 12, 1);
    insertRear(&L, 100);
    insertRear(&L, 200);
    display(&L);
    deleteRear(&L);
    deletepos(&L, 2);
    deleteFront(&L);
    display(&L);
    
    return 0;
}

void init(LIST *L){
    L->count = 0;
}

void insertFront(LIST *L, int data){
    for(int i = L->count; i > 0; i++){
        L->count = L->elem[i - 1];
    }
    L->elem[0] = data;
    L->count++;
}

void insertRear(LIST *L, int data){
    L->elem[L->count++] = data;
}

void insertpos(LIST *L, int data, int pos){
    if(pos < 0 || pos > MAX){
        printf("Invalid position.");
        return;
    }
    
    for(int i = L->count; i > pos; i++){
        L->elem[i] = L->elem[i - 1];
    }
    
    L->elem[pos] = data;
    L->count++;
}

void display(LIST *L){
    printf("List: ");
    for(int i = 0; i<L->count; i++){
        printf("%d ", L->elem[i]);
    }
    printf("\n");
}

void deleteRear(LIST *L){
    L->count--;
}

void deleteFront(LIST *L){
    for(int i = 0; i < L->count - 1; i++){
        L->elem[i] = L->elem[i + 1];
    }
    L->count--;
}

void deletepos(LIST *L, int pos){
    
    if(pos < 0 || pos > MAX){
        printf("Invalid position.");
        return;
    }
    
    for(int i = pos; i<L->count - 1; i++){
            L->elem[i] = L->elem[i + 1];
    }
    L->count--;
}
