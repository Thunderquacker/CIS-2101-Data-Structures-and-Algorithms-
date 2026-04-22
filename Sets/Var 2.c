// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct{
    unsigned int field;
} Set;

void init(Set *s);
void insert(Set *s, int elem);
void deleteSet(Set *s, int elem);
bool find(Set s, int elem);
Set intersec(Set A, Set B);
Set union_set(Set A, Set B);
Set diff(Set A, Set B);
void display(Set s);


int main() {
    // Write C code here
    Set A, B, result;
    init(&A);
    
    insert(&A, 1);
    insert(&A, 7);
    display(A);
    
    init(&B);
    insert(&B, 6);
    insert(&B, 1);
    display(B);
    
    printf("Intersection: ");
    result = intersec(A, B);
    display(result);
    
    printf("Difference: ");
    result = diff(A, B);
    display(result);
    
    printf("Union: ");
    result = union_set(A, B);
    display(result);

    return 0;
}

void init(Set *s){
    s->field = 0;
}

void insert(Set *s, int elem){
    if(elem >= 0 && elem < 8){
        s->field |= (1 << elem);
    }
}

void deleteSet(Set *s, int elem){
    if(elem >= 0 && elem < 8){
        s->field &= ~(elem << 8);
    }
} 

bool find(Set s, int elem){
    if(elem < 0 || elem >= 8) return false;
        return (s.field & (1 << elem)) != 0;
}

Set union_set(Set A, Set B){
    Set result;
    result.field = A.field | B.field;
    return result;
}

Set intersec(Set A, Set B){
    Set result;
    result.field = A.field & B.field;
    return result;
}

Set diff(Set A, Set B){
    Set result;
    result.field = A.field & ~B.field;
    return result;
}

void display(Set s){
    bool first = true;
    printf("{");
    for(int i = 0; i < 8; i++){
        if(find(s, i)){
             if(!first)
                printf(",");
            printf("%d", i);
                bool first = false;
        }
    }
    printf("}\n");
}



