#include <stdio.h>
#include <stdbool.h>

void init(unsigned char *set);
void insert(unsigned char *set, int elem);
unsigned char set_union(unsigned char A, unsigned char B);
unsigned char set_intersection(unsigned char A, unsigned char B);
unsigned char set_difference(unsigned char A, unsigned char B);
void display(unsigned char set);

int main(){
    
    unsigned char A, B, result;
    
    init(&A);
    insert(&A, 1);
    insert(&A, 0);
    insert(&A, 3);
    
    init(&B);
    insert(&B, 5);
    insert(&B, 0);
    insert(&B, 6);
    
    printf("Set A: "); display(A);
    printf("Set B: "); display(B);
    
    result = set_union(A, B); 
    printf("Union (A | B) "); display(result);
    
    result = set_intersection(A, B);
    printf("Intersection (A & B) "); display(result);
    
    result = set_difference(A, B);
    printf("Difference (~A & B) "); display(result);
    
    
    
}

void init(unsigned char *set){
    *set = 0;
}

void insert(unsigned char *set, int elem){
    if(elem >= 0 && elem < 8){
        *set |= (1 << elem);
    }
}

unsigned char set_union(unsigned char A, unsigned char B){
    return A | B;
}

unsigned char set_intersection(unsigned char A, unsigned char B){
    return A & B;
}

unsigned char set_difference(unsigned char A, unsigned char B){
    return ~A & B;
}

bool find(unsigned char set, int elem){
    return (set & (1 << elem)) != 0;
}

void display(unsigned char set){
    bool first = true;
    printf("{");
    for(int i = 0; i < 8; i++){
        if(find(set, i)){
            if(!first) printf(",");
            printf("%d", i);
            first = false;
        }
    }
    printf("}\n");
}
