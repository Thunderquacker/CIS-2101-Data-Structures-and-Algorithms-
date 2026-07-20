// Online C compiler to run C program online
#include <stdio.h>
#define MAX 10

typedef struct{
    int data[MAX];
    int lastIndex;
}Tree;

void initTree(Tree *T);
void populateTree(Tree *T, int arr[], int size);
void insertTree(Tree *T, int data);
int deleteMin(Tree *T);
void display(Tree T);

int main() {
    // Write C code here
    Tree T;
    int arr[] = {4, 2, 5, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    initTree(&T);
    populateTree(&T, arr, size);
    
    printf("Elements in order: ");
    display(T);

    return 0;
}

void initTree(Tree *T){
    T->lastIndex = -1;
}

void populateTree(Tree *T, int arr[], int size){
    for(int i = 0; i < size; i++){
        insertTree(T, arr[i]);
    }
}

void insertTree(Tree *T, int data){
    if(T->lastIndex + 1 < MAX){
        int child = ++T->lastIndex;
        int parent = (child - 1) / 2;
        
        while(child > 0 && T->data[parent] > data){
            T->data[child] = T->data[parent];
            
            child = parent;
            parent = (parent - 1) / 2;
        }
        
        T->data[child] = data;
    }
}

int deleteMin(Tree *T){
    int temp = -1;
    if(T->lastIndex >= 0){
        temp = T->data[0];
        int data = T->data[T->lastIndex--];
        
        int parent = 0;
        int LC = parent * 2 + 1;
        int RC = LC + 1;
        
        int child = T->data[LC] < T->data[RC] ? LC : RC;
        
        while(child <= T->lastIndex && T->data[child] < data){
            T->data[parent] = T->data[child];
            
            parent = child;
            LC = parent * 2 + 1;
            RC = LC + 1;
            child = T->data[LC] < T->data[RC] ? LC : RC;
        }
        T->data[parent] = data;
    }
    return temp;
}

void display(Tree T){
    int temp;
    while((temp = deleteMin(&T)) != -1){
        printf("%d ", temp);
    }
}
