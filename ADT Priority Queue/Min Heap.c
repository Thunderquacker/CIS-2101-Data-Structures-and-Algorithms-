#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct{
    int elem[MAX];
    int lastIndex;
}MinHeap;

void init(MinHeap *T);
void populate(MinHeap *T, int arr[], int size);
void insert(MinHeap *T, int data);
int deleteMin(MinHeap *T);
void display(MinHeap T);

int main(){
    
    MinHeap T;
    
    int arr[] = {100, 50, 46, 47, 31};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    init(&T);
    populate(&T, arr, size);
    display(T);
    
    return 0;
}

void init(MinHeap *T){
    T->lastIndex = -1;
}

void populate(MinHeap *T, int arr[], int size){
    for(int i = 0; i < size; i++){
        insert(T, arr[i]);
    }
}

void insert(MinHeap *T, int data){
    if(T->lastIndex + 1 < MAX){
        int child = ++T->lastIndex;
        int parent = (child - 1) / 2;
        
        while(child > 0 && T->elem[parent] > data){
            T->elem[child] = T->elem[parent];
            child = parent;
            parent = (parent - 1) / 2;
        }
        T->elem[child] = data;
    }
}

int deleteMin(MinHeap *T){
    int temp = -1;
    if(T->lastIndex >= 0){
        temp = T->elem[0];
        int data = T->elem[T->lastIndex--];
        
        int parent = 0;
        int LC = parent * 2 + 1;
        int RC = LC + 1;
        
        int child = T->elem[LC] < T->elem[RC] ? LC : RC;
        
        while(child <= T->lastIndex && T->elem[child] < data){
            T->elem[parent] = T->elem[child];
            
            parent = child;
            LC = parent * 2 + 1;
            RC = LC + 1;
            child = T->elem[LC] < T->elem[RC] ? LC : RC;
        }
        T->elem[parent] = data;
    }
    return temp;
}

void display(MinHeap T){
    int temp;
    while((temp = deleteMin(&T)) != -1){
        printf("%d ", temp);
    }
}

