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
void reverseElements(CA* q, int k);


CA* createQueue(){
    CA* q = (CA*)malloc(sizeof(CA));
    q->count = 0;
    q->front = 0;
    q->rear = MAX - 1;
    return q;
}

void enqueue(Queue* q, char data){
    if (q->count == MAX){
        printf("Queue is full\n");
        return;
    }

    q->rear = (q->rear - 1 + MAX) % MAX;
    q->data[q->rear] = data;

    if (q->count == 0) {
        q->front = q->rear;  // 🔥 FIX
    }

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
        current = (current + 1) % MAX;
    }
}

void reverseElements(CA *q, int k){
    if(k > q->count || k <= 0) {
        printf("Cant print");
        return;
    }
    CA* temp = createQueue();
    
   char stack[MAX];
   int top = -1;
   
   for(int i = 0; i < k; i++){
       stack[++top] = dequeue(q);
   }
   
   while(top >= 0){
       enqueue(q, stack[top--]);
   }
   
   int remaining = q->count - k;
   
   for(int i = 0; i < remaining; i++){
       enqueue(q, dequeue(q));
   }
}
int main(){
    
    
    CA* q = createQueue(MAX);
    
    
    enqueue(q, 'A');
    enqueue(q, 'B');
    enqueue(q, 'C');
    enqueue(q, 'D');
    enqueue(q, 'E');
    enqueue(q, 'F');
    display(q);
    reverseElements(q, 3);
    display(q);
    
    
    
    
    return 0;
}


