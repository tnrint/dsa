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
    q->front = q->rear = NULL;                                          //initialize the front and rear pointers of the queue to NULL
}

int isEmpty(Queue q){
    return (q.front == NULL && q.rear == NULL)? 1 : 0;                  //check if the queue is empty by verifying if both front and rear pointers are NULL
}

int isFull(Queue q){                                                    //it basically checks if theres still memory in the pc which cant be full O_O?
    LIST temp = malloc(sizeof(struct node));                            //attempt to allocate memory for a new node to check if the queue is full
    if(temp != NULL){                                                   //if memory allocation is successful, the queue is not full
        free(temp);                                                     //free the allocated memory for the temporary node
        return 0;                                                       //return 0 to indicate that the queue is not full
    }
    return 1;                                                           //if memory allocation fails, the queue is full, return 1 to indicate that the queue is full
}

void enqueue(Queue *q, Song s){
    LIST temp = malloc(sizeof(struct node));                            //attempt to allocate memory for a new node to add to the queue
    if(temp != NULL){
        if(s.songYear < 1980 && s.songYear > 1950){                     //check if the song year is between 1950 and 1980 before enqueuing
            temp->S = s;                                                //assign the song data to the new node
            temp->next = NULL;                                          //set the next pointer of the new node to NULL since it will be the last node in the queue
            if(q->front == NULL){                                       //if the queue is empty, set both front and rear pointers to the new node
                q->front = temp;                                        //if the queue is not empty, link the new node to the end of the queue and update the rear pointer
            } else {
                q->rear->next = temp;                                   //link the new node to the end of the queue
            }
        q->rear = temp;                                                 //update the rear pointer to the new node
        }
    }
}

void dequeue(Queue *q){
    if(q->front != NULL){                                               //check if the queue is not empty before dequeuing an element
        LIST temp = q->front;                                           //store the current front node in a temporary variable to free its memory after updating the front pointer
        q->front = temp->next;                                          //update the front pointer to the next node in the queue
        if(temp == q->rear){                                            //if the dequeued node is the rear node, update the rear pointer to NULL since the queue will be empty after this operation
            q->rear = NULL;                                             //update the rear pointer to NULL if the dequeued node is the rear node
        }
        free (temp);                                                    //free the memory allocated for the dequeued node to prevent memory leaks
    }
}