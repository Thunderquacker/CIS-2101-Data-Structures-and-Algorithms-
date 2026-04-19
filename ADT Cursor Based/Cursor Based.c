#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct{
    int data;
    int next;
}Cell, HeapSpace[MAX];

typedef struct{
    HeapSpace H;
    int avail;
}VHeap;

typedef int List;


void init(VHeap *VH);
int allocSpace(VHeap *VH);
void dealloc(VHeap *VH, int index);
void insertFirst(VHeap *VH, List *L, int data);
void deleteFirst(VHeap *VH, List *L);
void display(VHeap VH, List L);


int main(){
    
    VHeap V;
    List L = -1;
    
    init(&V);
    
    insertFirst(&V, &L, 1);
    display(V, L);
    
    
    
    return 0;
}

void init(VHeap *VH){
    
    int i;
    
    for(i = 0; i < MAX - 1; i++){
        VH->H[i].next = i + 1;
    }
    
    VH->H[MAX - 1].next = -1;
    VH->avail = 0;
}

int allocSpace(VHeap *VH){
    
    int res = VH->avail;
    if(res != -1){
        VH->avail = VH->H[res].next;
    }
    return res;
}


void insertFirst(VHeap *VH, List *L, int data){
    int newNode = allocSpace(VH);
    if(newNode != -1){
        VH->H[newNode].data = data;
        VH->H[newNode].next = *L;
        *L = newNode;
    }
}

void deleteFirst(VHeap *VH, List *L){
    
    if(*L != -1){
        int temp = *L;
        *L = VH->H[temp].next;
        dealloc(VH, temp);
    }
}

void dealloc(VHeap *VH, int index){
    
    if(index >= 0 && index < MAX){
        VH->H[index].next = VH->avail;
        VH->avail = index;
    }
}

void display(VHeap VH, List L){
    
    while(L != -1){
        printf("%d", VH.H[L].data);
        L = VH.H[L].next;
    }
}
