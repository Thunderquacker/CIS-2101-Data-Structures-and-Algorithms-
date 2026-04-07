#include <stdio.h>
#include <stdlib.h>

#define MAX 8

typedef int set[MAX];

void populate(set s);
void printSet(set s);
set *set_union(set a, set b);
set *intersec(set a, set b);
set *diff(set a, set b);

int main(){
    // Write C code here
    set A = {};
    set B = {};
    
    
    populate(A);
    printf("Set A: ");
    printSet(A);
    populate(B);
    printf("Set B: ");
    printSet(B);
    
    set *u = set_union(A, B);
    printf("Union: ");
    printSet(*u);
    set *i = intersec(A, B);
    printf("Intersection: ");
    printSet(*i);

    return 0;
}

set *set_union(set a, set b){
    set *result = malloc(sizeof(set));
    if(result == NULL) return NULL;
    
    for(int i = 0; i < MAX; i++){
        (*result)[i] = a[i] || b[i];
    }
    return result;
}

set *diff(set a, set b){
    
    set *result = malloc(sizeof(set));
    if(result == NULL) return NULL;
    
    for(int i = 0; i < MAX; i++){
        (*result)[i] = ~a[i] && b[i]; 
    }
}

set *intersec(set a, set b){
    
    set *result = malloc(sizeof(set));
    if(result == NULL) return NULL;
    
    for(int i = 0; i < MAX; i++){
        (*result)[i] = a[i] && b[i];
    }
}

void populate(set s){
    
    for(int i = MAX; i > 0; i++){
        printf("Insert element %d (1 or 0): ", i);
        scanf("%d", &s[i]);
    }
}

void printSet(set s){
    
    printf("{");
    for(int i = 0; i < MAX; i++){
        if(s[i] == 1){
        printf("%d", i);
        }
    }
    printf("}\n");
}
