#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    char name[300];
} Employee;

typedef struct node{
    Employee data;
    struct node *next;
} *List;

typedef struct{
    List front;
    List rear;
} Queue;

/* Function Prototypes */
void initialize(Queue *q);
void enqueue(Queue *q, Employee emp);
void dequeue(Queue *q);
void display(Queue *q);
void enqueueSorted(Queue *q, Employee emp);

void display(Queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    List temp = q->front;

    while (temp != NULL) {
        printf("ID: %d | Name: %s\n",
               temp->data.id, temp->data.name);
        temp = temp->next;
    }
}

void initialize(Queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

/* ================= ENQUEUE ================= */
void enqueue(Queue *q, Employee emp) {
    List newNode = (List)malloc(sizeof(struct node));
    
    newNode->data = emp;
    newNode->next = NULL;
    
    if(q->rear == NULL){
        q->front = newNode;
        q->rear = newNode;
    } else {
    
    q->rear->next = newNode;
    q->rear = newNode;
    
    }
    
    
}

/* ================= DEQUEUE ================= */
void dequeue(Queue *q) {
    
    List temp = q->front;
    
    q->front = q->front->next;
    
    if(q->front == NULL){
        q->rear = NULL;
    }
    
    free(temp);
}

void enqueueSorted(Queue *q, Employee emp){
    
    Queue temp;
    
    initialize(&temp);
    
    int flag = 0;
    
    while(q->front != NULL){
        Employee etemp = q->front->data;
        dequeue(q);
     if (emp.id < etemp.id) {
        enqueue(&temp, emp);
        flag++;
    }
    
    enqueue(&temp, etemp);
    } 
    
    if(flag != 1){
        enqueue(&temp, emp);
    }
    *q = temp;
}

int main(){
    
    Queue q;
    initialize(&q);
    
    Employee e1 = {10, "Alice"};
    Employee e2 = {20, "Daniel"};
    Employee e3 = {17, "Matthew"};
    
    enqueue(&q, e1);
    enqueue(&q, e2);
    enqueueSorted(&q, e3);
    
    display(&q);
    
    
    
    
    
    return 0;
}
