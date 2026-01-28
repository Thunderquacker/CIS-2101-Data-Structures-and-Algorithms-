#ifndef ARRAYLISTVAR3_H
#define ARRAYLISTVAR3_H

#define LENGTH 10

typedef struct {
	int *elemPtr;
	int count;
	int max;
}List;


List init(List L);
List insertPos(List L, int data, int pos);
List deletePos(List L, int pos);
int locate(List L, int data);
List insertSorted(List L, int data);
void display(List L);
List resize(List L);

#endif
