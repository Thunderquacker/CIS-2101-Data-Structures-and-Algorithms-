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

/* ================= ENQUEUE SORTED ================= */
void enqueueSorted(Queue *q, Employee emp) {
    
    List l = (List)malloc(sizeof(struct node));
    l->data = emp;
    l->next = NULL;
    
    if(q->front == NULL){
        q->front = q->rear = l;
        return;
    }
    
    List prev = NULL;
    List curr = q->front;
    
    while(curr != NULL && curr->data.id < emp.id){
        prev = curr;
        curr = curr->next;
    }
    
    if(prev == NULL){
        l->next = q->front;
        q->front = l;
    } else {
        prev->next = l;
        l->next = curr;
    }
    
    if(curr == NULL){
        q->rear = l;
    }
}

int main() {
    Queue q;
    initialize(&q);

    Employee e1 = {10, "Alice"};
    Employee e2 = {20, "Bob"};
    Employee e3 = {30, "Charlie"};

    enqueue(&q, e1);
    enqueue(&q, e2);
    enqueue(&q, e3);

    display(&q);
    printf("%s", "----------------------------------------------------------\n");

    dequeue(&q);
    display(&q);
   printf("%s", "----------------------------------------------------------\n");

    Employee e4 = {40, "Lima"};
    Employee e5 = {15, "Alpha"};
    Employee e6 = {25, "Tango"};

    enqueueSorted(&q, e4);
    enqueueSorted(&q, e5);
    enqueueSorted(&q, e6);

    display(&q);
    printf("%s", "----------------------------------------------------------\n");

    return 0;
}
