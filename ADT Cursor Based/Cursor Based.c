#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct{
    int data;
    int next;
}HeapSpace[MAX];

typedef struct{
    HeapSpace H;
    int avail;
}VHeap;

typedef int List;

void init(VHeap *VH);
int allocSpcae(VHeap *VH);
void dealloc(VHeap *VH, int index);
void display(VHeap VH, List L);
void insertFirst(VHeap *VH, List *L, int data);
void deleteFirst(VHeap *VH, List *L, int data);
void deleteAllOccurences(VHeap *VH, List *L, int data);
void insertSorted(VHeap *VH, List *L, int data);
void insertLast(VHeap *VH, List *L, int data);

int main(){
    
    VHeap V;
    List L;
    
    init(&V);
    L = -1;
    
    insertFirst(&V, &L, 100);
    insertLast(&V, &L, 1);
    insertSorted(&V, &L, 50);
    display(V, L);
    
    
    
    return 0;
}

void init(VHeap *VH){
    for(int i = 0; i < MAX - 1; i++){
        VH->H[i].next = i + 1;
    }
    VH->H[MAX - 1].next = -1;
    VH->avail = 0;
}

void dealloc(VHeap *VH, int index){
    VH->H[index].next = VH->avail;
    VH->avail = index;
}

int allocSpace(VHeap *VH){
    
    int index = VH->avail;
    
    if(index != -1){
        VH->avail = VH->H[index].next;
    }
    return index;
}

void insertFirst(VHeap *VH, List *L, int data){
    
    int newNode = allocSpace(VH);
    
    if(newNode != -1){
        VH->H[newNode].data = data;
        VH->H[newNode].next = *L;
        *L = newNode;
    }
}

void insertSorted(VHeap *VH, List *L, int data){
    
    int newNode = allocSpace(VH);
    
    VH->H[newNode].data = data;
    
    if(*L == -1 || VH->H[*L].data >= data){
        VH->H[newNode].next = *L;
        *L = newNode;
        return;
    }
    
    int temp = *L;
    while(VH->H[temp].next != -1 && VH->H[temp].data < data){
        temp = VH->H[temp].next;
    }
    VH->H[newNode].next = VH->H[temp].next;
    VH->H[temp].next = newNode;
}

void insertLast(VHeap *VH, List *L, int data){
    
    int newNode = allocSpace(VH);
    
    VH->H[newNode].data = data;
    VH->H[newNode].next = -1;
    
    if(*L == -1){
        *L = newNode;
    } else {
        int temp = *L;
        while(VH->H[temp].next != -1){
            temp = VH->H[temp].next;
        }
        VH->H[temp].next = newNode;
    }
}

void deleteFirst(VHeap *VH, List *L, int data){
    while(*L != -1 && VH->H[*L].data == data){
        int temp = *L;
        *L = VH->H[*L].next;
        dealloc(VH, temp);
    }
}

void display(VHeap VH, List L){
    
    int temp = L;
    
    while(temp != -1){
        printf("%d ", VH.H[temp].data);
        temp = VH.H[temp].next;
    }
}

