#include <stdio.h>
#include <stdbool.h>

void init(unsigned char *set);
void insert(unsigned char *set, int data);
unsigned char set_union(unsigned char A, unsigned char B);
unsigned char set_intersec(unsigned char A, unsigned char B);
unsigned char set_diff(unsigned char A, unsigned char B);
void display(unsigned char set);
void deleteSet(unsigned char *set, int data);
bool find(unsigned char set, int data);

int main(){
    
    unsigned char A, B, result;
    
    init(&A);
    printf("Set A: ");
    insert(&A, 2);
    insert(&A, 5);
    display(A);
    
    printf("Set B: ");
    init(&B);
   insert(&B, 6);
   insert(&B, 4);
    display(B);
    
    printf("Union: ");
    result = set_union(A, B);
    display(result);
    
    printf("Difference: ");
    result = set_diff(A, B);
    display(result);
    
    printf("Intersection: ");
    result = set_intersec(A, B);
    display(result);
    
    return 0;
}


void init(unsigned char *set){
    *set = 0;
}

void insert(unsigned char *set, int data){
    if(data >= 0 && data < 8){
        *set |= (1 << data);
    }
}

void deleteSet(unsigned char *set, int data){
    if(data >= 0 && data < 8){
        *set &= ~(1 << data);
    }
}


unsigned char set_union(unsigned char A, unsigned char B){
    return A | B;
}

unsigned char set_diff(unsigned char A, unsigned char B){
    return A & ~B;
}

unsigned char set_intersec(unsigned char A, unsigned char B){
    return A & B;
}

bool find(unsigned char set, int data){
    return (set & (1 << data)) != 0;
}

void display(unsigned char set){
    bool first = true;
    printf("\n{");
    for(int i = 0; i < 8; i++){
        if(find(set, i)){
        printf("%d", i);
        first = false;
        }
    }
    printf("}\n");
}
