#ifndef ARRAYLISTVAR2_H
#define ARRAYLISTVAR2_H

#define MAX 10

typedef struct {
	int elem[MAX];
	int count;
}Etype, *EPtr;

void init(EPtr L);
void insertPos(EPtr L, int data, int pos);
int Locate(EPtr L, int pos);
int retrieve(EPtr L, int data);
void insertSorted(EPtr L, int data);
void display(EPtr L);
void makeNull(EPtr L);

#endif
