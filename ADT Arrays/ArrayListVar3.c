#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10

typedef struct {
    int *elemPtr;
    int count;
    int max;
} List;

// --- Function Implementations ---

/**
 * Initializes the list by allocating memory for the array
 * and setting initial count and max values.
 */
List init(List L) {
    L.elemPtr = (int *)malloc(sizeof(int) * LENGTH);
    if (L.elemPtr == NULL) {
        printf("Memory allocation failed!\n");
        L.count = 0;
        L.max = 0;
        return L;
    }
    L.count = 0;
    L.max = LENGTH;
    return L;
}

/**
 * Resizes the dynamic array when the list is full.
 * Increases the capacity by LENGTH.
 */
List resize(List L) {
    L.max += LENGTH;
    int *temp = (int *)realloc(L.elemPtr, sizeof(int) * L.max);
    
    if (temp == NULL) {
        printf("Resize failed! Out of memory.\n");
        // Keep original pointers intact, but reduce max back to current count
        L.max -= LENGTH; 
    } else {
        L.elemPtr = temp;
    }
    return L;
}

/**
 * Inserts an element at a specific position (0-indexed).
 * Shifts elements to the right to make room.
 */
List insertPos(List L, int data, int pos) {
    // Check if the position is valid
    if (pos < 0 || pos > L.count) {
        printf("Invalid position %d for insertion.\n", pos);
        return L;
    }

    // If the list is full, resize it
    if (L.count == L.max) {
        L = resize(L);
        // If resize failed and we are still at capacity, abort
        if (L.count == L.max) return L; 
    }

    // Shift elements to the right
    for (int i = L.count; i > pos; i--) {
        L.elemPtr[i] = L.elemPtr[i - 1];
    }

    // Insert the data and update count
    L.elemPtr[pos] = data;
    L.count++;

    return L;
}

/**
 * Deletes an element at a specific position (0-indexed).
 * Shifts elements to the left to fill the gap.
 */
List deletePos(List L, int pos) {
    // Check if the list is empty or position is out of bounds
    if (pos < 0 || pos >= L.count) {
        printf("Invalid position %d for deletion.\n", pos);
        return L;
    }

    // Shift elements to the left
    for (int i = pos; i < L.count - 1; i++) {
        L.elemPtr[i] = L.elemPtr[i + 1];
    }

    // Update count
    L.count--;

    return L;
}

/**
 * Locates the first occurrence of data.
 * Returns the 0-based index if found, or -1 if not found.
 */
int locate(List L, int data) {
    for (int i = 0; i < L.count; i++) {
        if (L.elemPtr[i] == data) {
            return i; 
        }
    }
    return -1; 
}

/**
 * Inserts an element into a sorted list while maintaining the sorted order (Ascending).
 */
List insertSorted(List L, int data) {
    // Find the correct position to insert
    int i = 0;
    while (i < L.count && L.elemPtr[i] < data) {
        i++;
    }
    
    // Leverage the insertPos function to handle shifting and resizing
    return insertPos(L, data, i);
}

/**
 * Displays the contents of the list.
 */
void display(List L) {
    printf("List Elements [%d/%d]: ", L.count, L.max);
    if (L.count == 0) {
        printf("Empty\n");
        return;
    }
    
    for (int i = 0; i < L.count; i++) {
        printf("%d ", L.elemPtr[i]);
    }
    printf("\n");
}
