#ifndef ARRAYINSERTIONDELETION_H
#define ARRAYINSERTIONDELETION_H

bool insertFront(int a[], int *count, int item);
bool insertRear(int a[], int *count, int item);
bool insertAt(int a[], int *count, int item);
bool insertSorted(int a[], int *count, int item);
void displayArray(int a[], int *count);
bool deleteFront(int a[], int *count);
bool deleteRear(int a[], int *count);
bool deleteItem(int a[], int *count, int item);

#endif
