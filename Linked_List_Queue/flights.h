#ifndef FLIGHTS_H
#define FLIGHTS_H

typedef struct {
    int hours;
    int minutes;
} Time;

typedef struct {
    int id;
    char origin[50];
    char destination[50];
    Time departure_time;
    Time arrival_time;
} Flight;

typedef struct Node {
    Flight data;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
} FlightQueue;

void initQueue(FlightQueue *q);
int isQueueEmpty(FlightQueue q);
void enqueueFlight(FlightQueue *q, Flight f);
Flight dequeueFlight(FlightQueue *q);
Flight peekQueue(FlightQueue q);

#endif