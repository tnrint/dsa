#include <stdio.h>

typedef struct {
    char songName[50];
    int songYear;
    int duration;
}Song;

typedef struct node{
    Song S;
    struct node *next;
}*LIST;

typedef struct {
    LIST front;
    LIST rear;
}Queue;

void initQueue(Queue *q){
    q->front = q->rear = NULL;
}

int isEmpty(Queue q){
    return (q.front == NULL && q.rear == NULL)? 1 : 0;
}

int isFull(Queue q){
    LIST temp = malloc(sizeof(struct node));
    if(temp != NULL){
        free(temp);
        return 0;
    }
    return 1;
}

void enqueue(Queue *q, Song s){
    LIST temp = malloc(sizeof(struct node));
    if(temp != NULL){
        if(s.songYear < 1980 && s.songYear > 1950){
            temp->S = s;
            temp->next = NULL;
            if(q->front == NULL){
                q->front = temp;
            } else {
                q->rear->next = temp;
            }
        q->rear = temp;
        }
    }
}

void dequeue(Queue *q){
    if(q->front != NULL){
        LIST temp = q->front;
        q->front = temp->next;
        if(temp == q->rear){
            q->rear = NULL;
        }
        free (temp);
    }
}