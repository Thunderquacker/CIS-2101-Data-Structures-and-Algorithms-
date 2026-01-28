#ifndef ARRAYLISTVAR4_H
#define ARRAYLISTVAR4_H

#define LENGTH 10

typedef struct {
	int *elemPtr;
	int count;
	int max;
}List;

void init(List L);
void insertPos(List *L, int pos, int data);
void deletePos(List *L, int pos);
int locate(List *L, int data);
int retrieve(List *L, int pos);
void insertSorted(List *L, int data);
void display(List *L);

