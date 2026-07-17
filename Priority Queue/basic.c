#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct {
    int arr[MAX];
    int lastNDX;
} Heap;

// Initialize heap
void init(Heap *H) {
    H->lastNDX = -1;
}

// Insert (Min-Heap)
void insert(Heap *H, int data) {
    if(H->lastNDX + 1 < MAX){
        int child = ++H->lastNDX;
        int parent = (child - 1) / 2;
        
        while(child > 0 && H->arr[parent] > data){
            H->arr[child] = H->arr[parent];
            child = parent;
            parent = (parent - 1) / 2;
        }
        H->arr[child] = data;
    }
}

// Heapify down
void heapify(Heap *H, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left <= H->lastNDX && H->arr[left] < H->arr[smallest])
        smallest = left;

    if (right <= H->lastNDX && H->arr[right] < H->arr[smallest])
        smallest = right;

    if (smallest != i) {
        int temp = H->arr[i];
        H->arr[i] = H->arr[smallest];
        H->arr[smallest] = temp;

        heapify(H, smallest);
    }
}

// Delete min (highest priority)
int deleteMin(Heap *H) {
    if (H->lastNDX == -1) return -1;
    
    int min = H->arr[0];
    
    H->arr[0] = H->arr[H->lastNDX];
    H->lastNDX--;
    
    if(H->lastNDX >= 0){
        heapify(H, 0);
    }
    
    return min;
}

// Check if element exists
int isMember(Heap *H, int data) {
     for(int i = 0; i <= H->lastNDX; i++){
         if(H->arr[i] == data) return 1;
     }
     return 0;
}

// Display heap
void display(Heap *H) {
    if (H->lastNDX == -1) {
        printf("Heap is empty\n");
        return;
    }

    for (int i = 0; i <= H->lastNDX; i++) {
        printf("%d ", H->arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    Heap H;
    init(&H);

    insert(&H, 10);
    insert(&H, 5);
    insert(&H, 20);
    insert(&H, 3);
    insert(&H, 8);

    printf("Heap: ");
    display(&H);

    printf("Deleted min: %d\n", deleteMin(&H));

    printf("Heap after deletion: ");
    display(&H);

    printf("Is 8 in heap? %s\n", isMember(&H, 8) ? "Yes" : "No");

    return 0;
}
