// Online C compiler to run C program online
#include <stdio.h>
#include <stdbool.h>

#define MAX 20

typedef int Dict[MAX];

typedef enum{
    EMPTY = -1,
    DELETED = -2
}Status;

void init(Dict D);
int hash(int data);
void insert(Dict D, int data);
void deleteDic(Dict D, int data);
void display(Dict D);
bool inDict(Dict D, int data);

int main() {
    // Write C code here
    Dict D;
    
    init(D);
    
    insert(D, 100);
    insert(D, 50);
    
    display(D);

    return 0;
}

void init(Dict D){
    for(int i = 0; i < MAX; i++){
        D[i] = EMPTY;
    }
}

int hash(int data){
    return data % MAX;
}

void insert(Dict D, int data){
    
    int start = hash(data);
    int index = start;
    int avail = -1;
    bool isFull = false;
    
    while(!isFull && D[index] != data && D[index] != EMPTY){
        if(D[index] == DELETED && avail == -1){
            avail = index;
        }
        
        index = (index + 1) % MAX;
        
        if(index == start){
            isFull = true;
        }
    }
    
    if(isFull && avail == -1){
        printf("Dictionary is full.");
    } else if(D[index] == EMPTY || avail != -1){
        D[(avail == -1) ? index : avail] = data;
    }
}

bool inDict(Dict D, int data){
    int start = hash(data);
    int index = start;
    int avail = -1;
    bool isFull = false;
    
    while(!isFull && D[index] != data && D[index] != EMPTY){
        index = (index + 1) % MAX;
        
        if(index = start){
            isFull = true;
        }
    }
    return (D[index] == data) ? true : false;
}

void deleteDic(Dict D, int data){
    int start = hash(data);
    int index = start;
    int avail = -1;
    bool isFull = false;
    
    while(!isFull && D[index] != data && D[index] != EMPTY){
        index = (index + 1) % MAX;
        
        if(index == start){
            isFull = true;
        }
        
        if(D[index] == data){
            D[index] = DELETED;
        }
    }
}

void display(Dict D){
    
    for(int i = 0; i < MAX; i++){
        if(D[i] == EMPTY){
            printf("EMPTY. ");
        } else if(D[i] == DELETED){
            printf("DELETED. ");
        } else {
            printf("%d ", D[i]);
        }
    }
}
