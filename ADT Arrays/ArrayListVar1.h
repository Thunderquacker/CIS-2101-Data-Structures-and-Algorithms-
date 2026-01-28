#ifndef ARRAYLISTVAR1_H
#define ARRAYLISTVAR1_H

#define MAX 10

typedef struct {
	int elem[MAX];
	int count;
}List;

List init(List L);
List insertPos(List L, int pos, int data);
List deletePos(List L, int pos);
int locate(List L, int data);
List insertSorted(List L, int data);
void display(List L);

#endif
