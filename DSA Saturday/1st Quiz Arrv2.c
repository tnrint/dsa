Queue *initialize(){
    Queue *G = malloc(sizeof(Queue));
    if(G != NULL){
        G->front = 4;
        G->rear = NULL;
    }
}

bool isEmpty(Queue *G){
    return ((G->rear - 1) % MAX == G->front)? true : false;
}

bool isFull(Queue *G){
    return ((G->rear - 2) % MAX == G->front)? true : false;
}

void enqueue(Queue *G, Person H){
    if((G->rear - 2) % MAX != G->front){
        G->rear = (G->rear - 1) % MAX;
        G->elems[G->rear] = H;
    }
}

void dequeue(Queue *G){
    if((G->rear - 1) % MAX != G->front){
        G->front = (G->front - 1) % MAX;
    }
}

Person front(Queue G){
    return ((G.rear - 1) % MAX != G.front)? G.elems[G.front] : '\0';
}