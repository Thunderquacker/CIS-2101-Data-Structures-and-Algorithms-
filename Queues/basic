#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct{
    int front;
    int rear;
    int size;
    int count;
    int* array;
}CA;

CA* createQueue(int size);
void enqueue(CA* q, int data);
int dequeue(CA* q);
void display(CA* q);

int main(){
    
    CA* q = createQueue(MAX);
    
    enqueue(q, 1);
    enqueue(q, 100);
    
    display(q);
    
    dequeue(q);
    
    display(q);
    
    
    return 0;
}


CA* createQueue(int size){
    CA* q = (CA*)malloc(sizeof(CA));
    q->size = size;
    q->front = 0;
    q->rear = -1;
    q->count = 0;
    q->array = (int*)malloc(q->size * sizeof(int)); 
    return q;
}

void enqueue(CA* q, int data){
    if(q->count == q->size){
        printf("Queue Overflow.");
        return;
    }
    
    q->rear = (q->rear + 1) % q->size;
    q->array[q->rear] = data;
    q->count++;
}

int dequeue(CA* q){
    
    if(q->count == 0){
        printf("Queue underflow. ");
        return -1;
    }
    
    int item = q->array[q->rear];
    q->rear = (q->rear + 1) % q->size;
    q->count--;
    return item;
}

void display(CA* q){
    
    
    
    printf("Queue Elements: ");
    int current = q->front;
    
    for(int i = 0; i < q->count; i++){
        printf("%d ", q->array[current]);
        current = (current + 1) % q->size;
    }
    
    printf("\n");
}
