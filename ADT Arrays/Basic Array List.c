#include <stdio.h>

#define MAX 20

typedef struct{
    int data[MAX];
    int count;
}LIST;

void init(LIST *L);
void display(LIST L);
void insertFirst(LIST *L, int data);
void insertRear(LIST *L, int data);
void insertPos(LIST *L, int data, int pos);
void deleteFirst(LIST *L);
void deleteRear(LIST *L);
void deleteAt(LIST *L, int pos);

int main(){
    
    LIST L;
    init(&L);
    
    insertFirst(&L, 11);
    insertRear(&L, 10);
    insertFirst(&L, 100);
    insertRear(&L, 15);
    insertPos(&L, 10, 0);
    
    display(L);
    
    
    return 0;
}

void init(LIST *L){
    L->count = 0;
}

void insertFirst(LIST *L, int data){
    for(int i = L->count; i > 0; i--){
        L->data[i] = L->data[i - 1];
    }
    L->data[0] = data;
    L->count++;
}

void insertRear(LIST *L, int data){
    
    L->data[L->count++] = data;
}

void insertPos(LIST *L, int data, int pos){
    if (pos >= 0 && pos <= L->count && L->count < MAX) {
    for(int i = L->count; i > pos; i--){
        L->data[i] = L->data[i - 1];
    }
    L->data[pos] = data;
    L->count++;
    }
}

void deleteFront(LIST *L){
    for(int i = 0; i < L->count; i++){
        L->data[i] = L->data[i + 1];
    }
    L->count--;
}

void deleteRear(LIST *L){
    L->count--;
}

void deletePos(LIST *L, int pos){
    for(int i = pos; i < L->count - 1; i++){
        L->count = L->data[i + 1];
    }
    L->count--;
}

void display(LIST L){
    for(int i = 0; i < L.count; i++){
        printf("%d ", L.data[i]);
    }
}
