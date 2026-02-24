#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

typedef struct{
    struct Node *front, *rear;
}Queue;

Queue* createQueue();
void enqueue(Queue* q, int data);
int dequeue(Queue* q);
void display(Queue* q);

int main(){
    
    Queue* q = createQueue();
    
    enqueue(q, 12);
    enqueue(q, 100);
    display(q);
    
    dequeue(q);
    display(q);
    
    return 0;
}

Queue* createQueue(){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue* q, int data){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    
    if(q->rear == NULL){
        q->front = q->rear = temp;
        return;
    }
    
    q->rear->next = temp;
    q->rear = temp;
    
}

int dequeue(Queue* q){
    
    if(q->front == NULL){
       printf("Queue is empty.");
       return -1;
    }
    
    struct Node* temp = q->front;
    int item = temp->data;
    
    q->front = q->front->next;
    
    if(q->front == NULL){
        q->rear = NULL;
    }
    
    free(temp);
    return item;
}

void display(Queue* q){
    
    if(q->front == NULL){
        printf("Queue is empty. ");
        return;
    }
    
    struct Node* temp = q->front;
    
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
