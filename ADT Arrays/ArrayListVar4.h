#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10

typedef struct {
    int *elemPtr;
    int count;
    int max;
} List;

// Helper function to handle dynamic resizing when the list is full
void resize(List *L) {
    L->max += LENGTH;
    int *temp = (int *)realloc(L->elemPtr, sizeof(int) * L->max);
    
    if (temp == NULL) {
        printf("Resize failed! Out of memory.\n");
        L->max -= LENGTH; // Revert max back to current capacity
    } else {
        L->elemPtr = temp;
    }
}

/**
 * Initializes the list structure.
 * Note: Changed to List *L to ensure the allocation persists outside the function.
 */
void init(List *L) {
    L->elemPtr = (int *)malloc(sizeof(int) * LENGTH);
    if (L->elemPtr == NULL) {
        printf("Initialization failed! Out of memory.\n");
        L->count = 0;
        L->max = 0;
        return;
    }
    L->count = 0;
    L->max = LENGTH;
}

/**
 * Inserts an element at a specific 0-indexed position.
 * Shifts elements to the right to make room.
 */
void insertPos(List *L, int pos, int data) {
    // Check for valid insertion bounds
    if (pos < 0 || pos > L->count) {
        printf("Invalid position %d for insertion.\n", pos);
        return;
    }

    // Resize if array capacity is reached
    if (L->count == L->max) {
        resize(L);
        if (L->count == L->max) return; // Resize failed
    }

    // Shift elements to the right
    for (int i = L->count; i > pos; i--) {
        L->elemPtr[i] = L->elemPtr[i - 1];
    }

    // Insert data and update count
    L->elemPtr[pos] = data;
    L->count++;
}

/**
 * Deletes an element at a specific 0-indexed position.
 * Shifts elements to the left to fill the gap.
 */
void deletePos(List *L, int pos) {
    if (pos < 0 || pos >= L->count) {
        printf("Invalid position %d for deletion.\n", pos);
        return;
    }

    // Shift elements to the left
    for (int i = pos; i < L->count - 1; i++) {
        L->elemPtr[i] = L->elemPtr[i + 1];
    }

    L->count--;
}

/**
 * Locates the first occurrence of data.
 * Returns the 0-based index if found, or -1 if not found.
 */
int locate(List *L, int data) {
    for (int i = 0; i < L->count; i++) {
        if (L->elemPtr[i] == data) {
            return i;
        }
    }
    return -1;
}

/**
 * Retrieves the data at a specific 0-indexed position.
 * Returns -1 (or an error indicator) if out of bounds.
 */
int retrieve(List *L, int pos) {
    if (pos < 0 || pos >= L->count) {
        printf("Retrieval error: Position %d out of bounds.\n", pos);
        return -1; 
    }
    return L->elemPtr[pos];
}

/**
 * Inserts an element into a sorted list while maintaining ascending order.
 */
void insertSorted(List *L, int data) {
    int i = 0;
    // Find the correct insertion index
    while (i < L->count && L->elemPtr[i] < data) {
        i++;
    }
    // Reuse insertPos to handle shifting and potential resizing
    insertPos(L, i, data);
}

/**
 * Displays the contents of the list.
 */
void display(List *L) {
    printf("List [%d/%d]: ", L->count, L->max);
    if (L->count == 0) {
        printf("Empty\n");
        return;
    }
    for (int i = 0; i < L->count; i++) {
        printf("%d ", L->elemPtr[i]);
    }
    printf("\n");
}
