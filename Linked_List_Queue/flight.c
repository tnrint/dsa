#include <stdio.h>
#include <stdlib.h>
#include "flights.h"

void initQueue(FlightQueue *q){
    q->front = q->rear = NULL;
}

int isQueueEmpty(FlightQueue q){
    return (q.front == NULL)? 1 : 0;
}

void enqueueFlight(FlightQueue *q, Flight f){
    Node *temp = malloc(sizeof(struct Node));
    if(temp != NULL){
        temp->data = f;
        temp->next = NULL;
        if(q->front != NULL){
            q->rear->next = temp;
        } else {
            q->front = temp;
        }
        q->rear = temp;
    }
}

Flight dequeueFlight(FlightQueue *q){
    Flight temp;
    if(q->front != NULL){
        temp = q->front->data;
        Node *de = q->front;
        q->front = de->next;
        if(de == q->rear){
            q->rear = NULL;
        }
    free(de);
    }
    return temp;
}

Flight peekQueue(FlightQueue q){
    Flight empty = {0};
    return (q.front != NULL)? q.front->data : empty;
}