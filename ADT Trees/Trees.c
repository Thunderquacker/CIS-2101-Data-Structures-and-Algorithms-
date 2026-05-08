// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}*Tree;

void init(Tree *t);
void populateTree(Tree *t, int arr[], int size);
void insertTree(Tree *t, int data);
void insertRecursion(Tree *t, int data);
bool isFound(Tree t, int x);
bool isFoundRecursion(Tree t, int x);
void deleteElem(Tree *t, int x);
void preOrder(Tree t);


int main() {
    
    Tree t;
    
    int arr[] = {1, 10, 100, 50, 51};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    init(&t);
    populateTree(&t, arr, size);
    
    int x = 10;
    printf("LOOP: %d %s in the tree.\n", x, isFound(t, x) ? "IS" : "IS NOT");
    
    x = 100;
    printf("RECURSION: %d %s in the tree.\n", x, isFound(t, x) ? "IS" : "IS NOT");
    
    x = 50;
    printf("\nBefore deletion %d: (Pre-Order Traversal)\n", x);
    preOrder(t);
    
    deleteElem(&t, x);
    
    printf("\nAfter deletion %d: (Pre-Order Traversal)\n", x);
    preOrder(t);

    return 0;
}

void init(Tree *t){
    *t = NULL;
}

void populateTree(Tree *t, int arr[], int size){
    for(int i = 0; i < size; i++){
        insertTree(t, arr[i]);
    }
}

void insertTree(Tree *t, int data){
    Tree temp = (Tree)malloc(sizeof(struct node));
    
    if(temp != NULL){
        temp->data = data;
        temp->right = NULL;
        temp->left = NULL;
        
        Tree *trav;
        
        for(trav = t; *trav != NULL && (*trav)->data != data; trav = (*trav)->data > data ? &(*trav)->left : &(*trav)->right){}
        
        if(*trav == NULL){
            *trav = temp;
        }
    }
}

void insertRecursion(Tree *t, int data){
    if(*t == NULL){
        Tree temp = (Tree)malloc(sizeof(struct node));
        if(temp != NULL){
            temp->data = data;
            temp->left = NULL;
            temp->right = NULL;
            *t = temp;
        }
    }
    
    else if(data < (*t)->data){
        insertRecursion(&(*t)->left, data);
    } else if(data > (*t)->data){
        insertRecursion(&(*t)->right, data);
    }
}

bool isFound(Tree t, int x){
    
    while(t != NULL && t->data != x){
          t = (x < t->data) ? t->left : t->right;
    }
    return t != NULL;
}

bool isFoundRecursion(Tree t, int x){
    if(t == NULL) return false;
    if(t->data == x) return true;
    return (x < t->data) ? isFoundRecursion(t->left, x) : isFoundRecursion(t->right, x);
}

void deleteElem(Tree *t, int x){
    
    Tree *trav = t;
    Tree temp;
    
    while(*trav != NULL && (*trav)->data != x){
        if(x < (*trav)->data){
            trav = &(*trav)->left;
        } else {
            trav = &(*trav)->right;
        }
    }
    
    if(*trav != NULL){
        Tree temp = *trav;
        
        if(temp->left == NULL){
            *trav = temp->right;
            free(temp);
        } else if(temp->right == NULL){
            *trav = temp->left;
            free(temp);
        } else {
            Tree *successor = &(*trav)->right;
            while((*successor)->left != NULL){
                successor = &(*successor)->left;
            }
            (*trav)->data = (*successor)->data;
            
            Tree toFree = *successor;
            *successor = toFree->right;
            free(toFree);
        }
    }
}

void preOrder(Tree t){
    if(t != NULL){
        printf("%d ", t->data);
        preOrder(t->left);
        preOrder(t->right);
    } else {
        printf("-");
    }
}
