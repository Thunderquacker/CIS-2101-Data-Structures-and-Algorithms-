#ifndef LINKEDLISTVAR2_H
#define LINKEDLISTVAR2_H

typedef struct node{
    int data;
    struct node *next;
}Node;

typedef struct{
    Node *head;
    int count;
}List;

List init();
void empty(List *L);
void insertFirst(List *L, int data);
void insertLast(List *L, int data);
void insertPos(List *L, int data, int index);
void deleteStart(List *L);
void deleteLast(List *L);
void deletePos(List *L, int index);
int retrieve(List *L, int index);
int locate(List *L, int data);
void display(List *L);

#endif
