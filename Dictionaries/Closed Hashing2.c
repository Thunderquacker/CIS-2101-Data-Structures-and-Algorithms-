// Online C compiler to run C program online
#include <stdio.h>
#define MAX 20
#define PRIMARY_SIZE 10
#define Empty -1
#define Delete -2

typedef struct{
    int data;
    int next;
}Node;

typedef struct{
    Node nodes[MAX];
    int avail;
}Dict;

void init(Dict *D);
void insert(Dict *D, int data);
void deleteDic(Dict *D, int data);
int allocSpace(Dict *D);
void dealloc(Dict *D, int index);
void insertSorted(Dict *D, int data);
void display(Dict D);
int hash(int x);

int main() {
    // Write C code here
    Dict D;
    
    init(&D);
    insert(&D, 100);
    insert(&D, 5);
    insert(&D, 24);
    insert(&D, 33);
    insert(&D, 10);
    insertSorted(&D, 30);
    display(D);

    return 0;
}

void init(Dict *D){
    for(int i = 0; i < PRIMARY_SIZE; i++){
        D->nodes[i].data = Empty;
        D->nodes[i].next = -1;
    }
    
    for(int i = PRIMARY_SIZE; i < MAX - 1; i++){
        D->nodes[i].data = 0;
        D->nodes[i].next = i + 1;
    }
    D->nodes[MAX - 1].data = 0;
    D->nodes[MAX - 1].next = -1;
    
    D->avail = PRIMARY_SIZE;
}

int hash(int x){
    return x % PRIMARY_SIZE;
}

int allocSpace(Dict *D){
    int index = D->avail;
    
    if(index != -1){
        D->avail = D->nodes[index].next;
    }
    return index;
}

void insert(Dict *D, int data){
    
    int h = hash(data);
    
    if(D->nodes[h].data == Empty || D->nodes[h].data == Delete){
        D->nodes[h].data = data;
    } else {
        int newNode = allocSpace(D);
        
        if(newNode != -1){
        
        D->nodes[newNode].data = data;
        D->nodes[newNode].next = -1;
        
        int curr = h;
        
        while(D->nodes[curr].next != -1){
            curr = D->nodes[curr].next;
        }
        D->nodes[curr].next = newNode;
    } else {
        printf("Dictionary is full.\n");
    }
    }
}

int search(Dict *D, int data){
    
    int curr = hash(data);
    
    while(curr != -1){
        if(D->nodes[curr].data == data){
            return 1;
        }
    }
    return 0;
}

void dealloc(Dict *D, int index){
    D->nodes[index].data = D->avail;
    D->avail = index;
}

void deleteDic(Dict *D, int data){
    int curr = hash(data);
    int prev = -1;
    
    while(curr != -1 && D->nodes[curr].data != data){
        prev = curr;
        curr = D->nodes[curr].next;
    }
    
    if(curr != -1){
        if(prev == -1){
            int nextNode = D->avail;
            if(nextNode != -1){
                D->nodes[curr].data = D->nodes[prev].data;
                D->nodes[curr].next = D->nodes[prev].next;
                dealloc(D, nextNode);
            } else {
                D->nodes[curr].data = Empty;
            }
            } else {
                D->nodes[prev].next = D->nodes[curr].next;
                dealloc(D, curr);
            }
        }
    }

void insertSorted(Dict *D, int data){
    
    int h = hash(data);
    
    if(D->nodes[h].data == Empty || D->nodes[h].data == Delete){
        D->nodes[h].data = data;
        return;
    } 
    
    int newNode = allocSpace(D);
    if(newNode == -1){
        printf("Dictionary is full.\n");
        return;
    }
    
    if(data < D->nodes[h].data){
        D->nodes[newNode].data = D->nodes[h].data;
        D->nodes[newNode].next = D->nodes[h].next;
        
        D->nodes[h].data = data;
        D->nodes[h].next = newNode;
    } else {
        int curr = h;
        
        while(D->nodes[curr].next != -1 && D->nodes[D->nodes[curr].next].data < data){
            curr = D->nodes[curr].next;
        }
        D->nodes[newNode].data = data;
        D->nodes[newNode].next = D->nodes[curr].next;
        D->nodes[curr].next = newNode;
    }
}

void display(Dict D){
    printf("Index | Data | Next\n");
    for(int i = 0; i < MAX; i++){
        printf("%d %d %d\n", i, D.nodes[i].data, D.nodes[i].next);
    }
}
