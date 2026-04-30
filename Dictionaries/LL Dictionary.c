// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define MAX 10

typedef struct node{
    int data;
    struct node *next;
} *Nodetype;

typedef Nodetype Dictionary[MAX];

void init(Dictionary D);
int hash(int data);
void insert(Dictionary D, int data);
void deleteDic(Dictionary D, int data);
void display(Dictionary D);
bool inDic(Dictionary D, int data);

int* getInput(int *size);
void populateDic(Dictionary D, int arr[], int size);
void askToAdd(Dictionary D);
void askToDelete(Dictionary D);
int cont();

int main() {
    // Write C code here
    printf("Try programiz.pro");

    return 0;
}

void init(Dictionary D){
    for(int i = 0; i < MAX; i++){
        D[i] = NULL;
    }
}

void insert(Dictionary D, int data){
    int index = hash(data);
    
    Nodetype *trav;
    
    for(trav = &D[index]; *trav != NULL && (*trav)->data != data; trav = &(*trav)->next){}
    
    if(*trav == NULL){
        Nodetype temp = (Nodetype)malloc(sizeof(struct node));
        
        if(temp != NULL){
            temp->data = data;
            temp->next = NULL;
            *trav = temp;
        }
    }
}

bool inDic(Dictionary D, int data){
    int index = hash(data);
    
    Nodetype curr;
    
    for(curr = D[index]; curr != NULL && curr->data != data; curr = curr->next){}
    
    return (curr != NULL) ? true : false;
}

int cont(){
    char c;
    
    printf("Do you want to continue? [y/n] ");
    scanf("%c", &c);
    
    return (tolower(c) == 'y') ? 1 : 0;
}

void deleteDic(Dictionary D, int data){
    
    int index = hash(data);
    
    Nodetype *trav;
    
    for(trav = &D[index]; *trav != NULL && (*trav)->data; trav = &(*trav)->next){}
    
    if(*trav != NULL){
        Nodetype temp = *trav;
        *trav = temp->next;
        free(temp);
    }
}

int hash(int data){
    return data % MAX;
}

void display(Dictionary D){
    for(int i = 0; i < MAX; i++){
        printf("Row: %d", i);
        
        for(Nodetype curr = D[i]; curr != NULL; curr = curr->next){
            printf("%d", curr->data);
        }
        printf("\n");
    }
}

void populateDic(Dictionary D, int arr[], int size){
    for(int i = 0; i < size; i++){
        insert(D, arr[i]);
    }
}

int* getInput(int *size){
    
    int *arr;
    
    printf("Enter size: ");
    scanf("%d", &size);
    
    arr = (int*)malloc(sizeof (int) * (*size));
    
    for(int i = 0; i < *size; i++){
        printf("Element %d: ", i + 1);
        scanf("%d", arr + i);
    }
    return arr;
}

void askToDelete(Dictionary D){
    int data;
    printf("Enter element to delete: ");
    scanf("%d", &data);
    
    deleteDic(D, data);
}

void askToAdd(Dictionary D){
    int data;
    printf("Enter element to add: ");
    scanf("%d", &data);
    
    printf("The element %s in the Dictionary\n", (inDic(D, data) == true) ? "IS" : "IS NOT");
}
