// Online C compiler to run C program online
#include <stdio.h>
#include <stdbool.h>

typedef struct{
    unsigned int field;
}Set;

void init(Set *s);
void insert(Set *s, int data);
void deleteSet(Set *s, int data);
bool find(Set s, int data);
Set intersec(Set A, Set B);
Set unionSet(Set A, Set B);
Set diff(Set A, Set B);
void display(Set s);

int main(){
    
    Set A, B, C;
    
    init(&A);
    insert(&A, 6);
    insert(&A, 5);
    insert(&A, 3);
    
    init(&B);
    insert(&B, 6);
    insert(&B, 7);
    insert(&B, 3);
    
    init(&C);
    
    printf("Union: ");
    C = unionSet(A, B);
    display(C);
    
    printf("Intersection: ");
    C = intersec(A, B);
    display(C);
    
    return 0;
}


void init(Set *s){
    s->field = 0;
}

void insert(Set *s, int data){
    if(data >= 0 && data < 8){
        s->field |= (1 << data);
    }
}

void deleteSet(Set *s, int data){
    if(data >= 0 && data < 8){
        s->field &= ~(1 << data);
    }
}

bool find(Set s, int data){
    if(data < 0 && data >= 8) return false;
    return (s.field & (1 << data)) != 0;
}

Set intersec(Set A, Set B){
    Set result;
    result.field = A.field & B.field;
    return result;
}

Set unionSet(Set A, Set B){
    Set result;
    result.field = A.field | B.field;
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
            if(!first) printf(",");
            printf("%d", i);
            first = false;
        }
    }
    printf("}\n");
}

