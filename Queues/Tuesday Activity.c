#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 20

typedef struct{
    int front;
    int rear;
    int count;
    char array[MAX];
}CA;

CA* createQueue();
void enqueue(CA* q, char data);
char dequeue(CA* q);
void display(CA* q);
void reverse(CA* q);


CA* createQueue(){
    CA* q = (CA*)malloc(sizeof(CA));
    q->count = 0;
    q->front = 0;
    q->rear = MAX - 1;
    return q;
}

void enqueue(CA* q, char data){
    q->rear = (q->rear + 1) % MAX;
    q->array[q->rear] = data;
    q->count++;
}

char dequeue(CA* q){
    
    char item = q->array[q->front];
    q->front = (q->front + 1) % MAX;
    q->count--;
    return item;
}

void display(CA* q){
    
    printf("Current elements: ");
    char current = q->front;
    
    for(int i = 0; i < q->count; i++){
        printf("%c ", q->array[current]);
        current = (current + 1) % q->count;
    }
}


int main(){
    
    
    CA* q = createQueue(MAX);
    
    
    enqueue(q, 'A');
    enqueue(q, 'B');
    enqueue(q, 'C');
    enqueue(q, 'D');
    enqueue(q, 'E');
    display(q);
    if (!reverseK(q, 3)) {
        printf("Cant print shit");
    } else {
        display(q);
    }
    
    
    
    
    return 0;
}


