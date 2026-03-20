#include <stdio.h>
#include <stdlib.h>

struct node{
    char data;
    struct node *next;
};

typedef struct{
    struct node *front, *rear;
}Queue;

Queue* createQueue();
void enqueue(Queue *q, char data);
int dequeue(Queue *q);
char front(Queue *q);
void display(Queue *q);
void enqueueSorted(Queue *q, char data);

int main(){
    
    Queue* q = createQueue();
    
    enqueue(q, 'z');
    enqueue(q, 'b');
    
    enqueueSorted(q, 'a');
    
    display(q);
    
    return 0;
}

Queue* createQueue(){
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}


void enqueue(Queue *q, char data){
    
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    
    temp->data = data;
    temp->next = NULL;
    
    if(q->front == NULL){
        q->front = q->rear = temp;
    }
    
    q->rear->next = temp;
    q->rear = temp;
}

int dequeue(Queue *q){
    
    struct node *temp = q->front;
    int item = temp->data;
    
    q->front = q->front->next;
    
    if(q->front == NULL){
        q->rear = NULL;
    }
    
    free(temp);
    return item;
}

void display(Queue *q){
    
    struct node *temp = q->front;
    
    while(temp != NULL){
        printf("%c ", temp->data);
        temp = temp->next;
    }
}

void enqueueSorted(Queue *q, char data){
    
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    
    temp->data = data;
    temp->next = NULL;
    
    if(q->front == NULL || data < q->front->data){
       temp->next = q->front;
       q->front = temp;
       
       if(q->rear == NULL){
           q->rear = temp;
       }
       return;
    }
    
    struct node *prev = NULL;
    struct node *curr = q->front;
    
    while(curr != NULL && curr->data < data){
        prev = curr;
        curr = curr->next;
    }
    
   prev->next = temp;
   temp->next = curr;
   
   if(curr == NULL){
       q->rear = temp;
   }
}


