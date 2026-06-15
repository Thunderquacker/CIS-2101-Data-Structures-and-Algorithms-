#include <stdio.h>

#define MAX 10

typedef struct {
    int elem[MAX];
    int count;
} Etype, *EPtr;

/**
 * Initializes the list by setting the count to 0.
 */
void init(EPtr L) {
    L->count = 0;
}

/**
 * Inserts an element at a specific 0-indexed position.
 * Shifts elements to the right to make room.
 */
void insertPos(EPtr L, int data, int pos) {
    // Check if the list is full
    if (L->count >= MAX) {
        printf("Insertion failed: List is full.\n");
        return;
    }

    // Check for valid insertion bounds
    if (pos < 0 || pos > L->count) {
        printf("Invalid position %d for insertion.\n", pos);
        return;
    }

    // Shift elements to the right to create a gap
    for (int i = L->count; i > pos; i--) {
        L->elem[i] = L->elem[i - 1];
    }

    // Insert data and increment count
    L->elem[pos] = data;
    L->count++;
}

/**
 * Locates the position of a specific target data.
 * Returns the 0-based index if found, or -1 if not found.
 * (Adjusted from your prototype to match standard logical behavior)
 */
int Locate(EPtr L, int data) {
    for (int i = 0; i < L->count; i++) {
        if (L->elem[i] == data) {
            return i; // Found data, returning its index position
        }
    }
    return -1; // Data not found
}

/**
 * Retrieves the data element located at a specific 0-indexed position.
 * Returns -1 (or an error indicator) if the position is out of bounds.
 * (Adjusted from your prototype to match standard logical behavior)
 */
int retrieve(EPtr L, int pos) {
    if (pos < 0 || pos >= L->count) {
        printf("Retrieval error: Position %d out of bounds.\n", pos);
        return -1; 
    }
    return L->elem[pos];
}

/**
 * Inserts an element into a sorted list while maintaining ascending order.
 */
void insertSorted(EPtr L, int data) {
    // Check if the list is already full before trying to find a spot
    if (L->count >= MAX) {
        printf("Insertion failed: List is full.\n");
        return;
    }

    int i = 0;
    // Find the correct insertion index
    while (i < L->count && L->elem[i] < data) {
        i++;
    }

    // Reuse insertPos to handle the shifting and insertion logic safely
    insertPos(L, data, i);
}

/**
 * Displays the contents of the list.
 */
void display(EPtr L) {
    printf("List [%d/%d]: ", L->count, MAX);
    if (L->count == 0) {
        printf("Empty\n");
        return;
    }
    for (int i = 0; i < L->count; i++) {
        printf("%d ", L->elem[i]);
    }
    printf("\n");
}

/**
 * Resets the list to an empty state.
 * With static arrays, we simply reset the count to 0.
 */
void makeNull(EPtr L) {
    L->count = 0;
}
