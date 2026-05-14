// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct{
    int elements[MAX];
    int lastIndex;
}MaxHeap;

void init(MaxHeap *T);
void populateTree(MaxHeap *T, int size, int arr[]);
void insert(MaxHeap *T, int data);
int deleteMax(MaxHeap *T);
void display(MaxHeap T);


int main() {
    // Write C code here
    MaxHeap T;
    
    int arr[] = {100, 25, 46, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    init(&T);
    populateTree(&T, size, arr);
    
    printf("Elements are in order: ");
    display(T);

    return 0;
}

void init(MaxHeap *T){
    T->lastIndex = -1;
}

void insert(MaxHeap *T, int data){
    
    if(T->lastIndex < MAX - 1){
        int child = ++T->lastIndex;
        int parent = (child - 1) / 2;
        
        while(child > 0 && T->elements[parent] < data){
            T->elements[child] = T->elements[parent];
            
            child = parent;
            parent = (parent - 1) / 2;
        }
        T->elements[child] = data;
    }
}

void populateTree(MaxHeap *T, int size, int arr[]){
    for(int i = 0; i < size; i++){
        insert(T, arr[i]);
    }
}

int deleteMax(MaxHeap *T){
    int temp = -1;
    
    if(T->lastIndex >= 0){
        temp = T->elements[0];
        int data = T->elements[T->lastIndex--];
        
        int parent = 0;
        int LC = parent * 2 + 1;
        int RC = LC + 1;
        
        int child = 1;
        
       while(child <= T->lastIndex){
           if(child + 1 <= T->lastIndex && T->elements[child + 1] > T->elements[child]){
               child++;
           }
           if(data >= T->elements[child]) break;
           
           T->elements[parent] = T->elements[child];
           parent = child;
           child = parent * 2 + 1;
       }
      T->elements[parent] = data;
}
   return temp;
}

void display(MaxHeap T){
    int temp;
    while((temp = deleteMax(&T)) != -1){
        printf("%d ", temp);
    }
}
