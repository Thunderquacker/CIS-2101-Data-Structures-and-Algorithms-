#include <stdio.h>
#include "ArrayListVar1.h"

List init(List L){
    L.count = 0;
    return L;
}

List insertSorted(List L, int data){
    if (L.count >= MAX) {
        printf("Array Full\n");
        return L;
    }

    int i = L.count - 1;
    // Shift elements right while they are greater than data
    while (i >= 0 && L.data[i] > data) {
        L.data[i + 1] = L.data[i]; // Shift element right
        i--;
    }
    
    // Insert the data at the vacant slot
    L.data[i + 1] = data;
    L.count++;
    return L;
}


List insertPos(List L, int data, int pos){
    if(L.count >= MAX || pos < 0 || pos > L.count){
        printf("Insert failed. Invalid position.");
        return L;
    }
    
    for(int i = L.count; i > pos; i--){
        L.elem[i] = L.elem[i - 1];
    }
    
    L.elem[pos] = data;
    L.count++;
    return L;
}

List deletePos(List L, int pos){
    
    if(pos < 0 || pos > L.count){
        printf("Deletion failed.");
        return L;
    }
    
    for(int i = L.count; i < L.count - 1; i++){
        L.elem[i] = L.elem[i + 1];
    }
    
    L.count--;
    return L;
}

int locate(List L, int data){
    for(int i = 0; i < L.count; i++){
        if(L.elem[i] == data){
            return i;
        }
    }
    
    return -1;
}


void display(List L){
    printf("[");
    for(int i = 0; i<L.count; i++){
        printf("%d", L.elem[i]);
    }
    printf("] (Count: %d)\n", L.count);
}
