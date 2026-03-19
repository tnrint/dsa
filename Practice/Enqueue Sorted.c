#include <stdio.h>
#include <stdbool.h>
#define MAX 10

typedef struct {
	int elems[MAX];
	int rear;
	int front;
} Queue;

void initialize(Queue *);
void enqueueSorted(Queue *, int); //Implement your code in this function !!
void dequeue(Queue *);
void read(Queue);
int size(Queue);

int main() {
    int n;
    printf("Elems in queue: ");
    scanf("%d", &n);

	Queue Q;
	initialize(&Q);

    int input;

    for(int i = 0; i < n ; i++) {
        scanf("%d", &input);
        enqueueSorted(&Q, input);
    }

   read(Q);
}

void initialize(Queue *Q) {
	Q->front = 0;
	Q->rear = MAX - 1;
}

int size(Queue Q) {
	return (Q.rear - Q.front + MAX + 1) % MAX;
}

bool isEmpty(Queue Q) {
	return (Q.rear + 1) % MAX == Q.front;
}

bool isFull(Queue Q) {
	return (Q.rear + 2) % MAX == Q.front;
}

void enqueue(Queue *Q, int x) {
	if(!isFull(*Q)) {
		Q->rear = (Q->rear + 1) % MAX;
		Q->elems[Q->rear] = x;
	}
}

void enqueueSorted(Queue *Q, int x) { 
    //implement code here...
    Queue temp;
    initialize(&temp);
  
    while(!isEmpty(*Q) && Q->elems[Q->front] < x){
      enqueue(&temp, Q->elems[Q->front]);
      dequeue(Q);
    }
    
    enqueue(&temp, x);
    
    while(!isEmpty(*Q)){
        enqueue(&temp, Q->elems[Q->front]);
        dequeue(Q);
    }

  while(!isEmpty(temp)){
    enqueue(Q, temp.elems[temp.front]);
    dequeue(&temp);
  }
}

void dequeue(Queue *Q) {
	if(!isEmpty(*Q)) {
		Q->front = (Q->front + 1) % MAX;
	}
}

void read(Queue Q) {
	if(!isEmpty(Q)) {
		int i;
		int n = size(Q);
        printf("Sorted Queue: ");
		for(i = 0; i < n; i++) {
			int temp = Q.elems[Q.front];
			Q.front = (Q.front + 1) % MAX;
			printf("%d ", temp);
		}
	}
}
