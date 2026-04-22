#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 8
typedef bool Set[ARRAY_SIZE];

void init(Set set);
void insert(Set set, int element);
void deleteSet(Set set, int element);
bool find(Set set, int element);
void display(Set set);
void diff(Set A, Set B, Set C);
void intersec(Set A, Set B, Set C);
void set_union(Set A, Set B, Set C);

int main(){
    
    Set A, B, C;
    
    init(A);
    insert(A, 1);
    insert(A, 3);
    display(A);
    
    init(B);
    insert(B, 6);
    insert(B, 3);
    display(B);
    
    init(C);
    
    printf("Intersection: ");
    intersec(A, B, C);
    display(C);
    
    printf("Difference: ");
    diff(A, B, C);
    display(C);
    
    printf("Union: ");
    set_union(A, B, C);
    display(C);
    
    
    
    
    
    
    return 0;
}


void init(Set set) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        set[i] = false;
    }
}

void insert(Set set, int element) {
    if (element >= 0 && element < ARRAY_SIZE) {
        set[element] = true;
    }
}

void deleteSet(Set set, int element) {
    if (element >= 0 && element < ARRAY_SIZE) {
        set[element] = false;
    }
}

bool find(Set set, int element) {
    if (element >= 0 && element < ARRAY_SIZE) {
        return set[element];
    }
    return false;
}

void set_union(Set A, Set B, Set C) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        C[i] = A[i] || B[i];
    }
}

void intersec(Set A, Set B, Set C) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        C[i] = A[i] && B[i];
    }
}

void diff(Set A, Set B, Set C) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        C[i] = A[i] && !B[i];
    }
}

void display(Set set) {
    bool first = true;
    printf("{");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (set[i]) {
            if (!first) printf(", ");
            printf("%d", i);
            first = false;
        }
    }
    printf("}\n");
}
