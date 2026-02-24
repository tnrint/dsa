#include <stdio.h>                                                              //This problem is about enqueue and dequeue in a circular array starting front in 4th index and circulating in counter-clockwise direction. The queue is full when rear is 2 positions behind front and empty when rear is 1 position behind front.
Queue *initialize(){                                                            //initialize the queue
    Queue *G = malloc(sizeof(Queue));                                           //allocate memory for the queue
    if(G != NULL){                                                              //check if memory allocation was successful
        G->front = 4;                                                           //initialize front to 4
        G->rear = NULL;                                                         //  initialize rear to NULL
    }

    return G;                                                                   //return the initialized queue
}

bool isEmpty(Queue *G){
    return ((G->rear - 1) % MAX == G->front)? true : false;                     //check if the queue is empty by comparing rear and front
}

bool isFull(Queue *G){
    return ((G->rear - 2) % MAX == G->front)? true : false;                     //check if the queue is full by comparing rear and front
}

void enqueue(Queue *G, Person H){
    if((G->rear - 2) % MAX != G->front){                                        //check if the queue is not full before enqueuing an element
        G->rear = (G->rear - 1) % MAX;                                          //update rear to the next position in counter-clockwise direction
        G->elems[G->rear] = H;                                                  //add the new element to the rear of the queue counter-clockwise
    }
}

void dequeue(Queue *G){
    if((G->rear - 1) % MAX != G->front){                                        //check if the queue is not empty before dequeuing an element
        G->front = (G->front - 1) % MAX;                                        //update front to the next position in counter-clockwise direction
    }
}

Person front(Queue G){
    return ((G.rear - 1) % MAX != G.front)? G.elems[G.front] : '\0';            //return the front element of the queue if it's not empty, otherwise return null character
}