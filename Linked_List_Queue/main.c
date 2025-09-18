#include <stdio.h>
#include <stdlib.h>
#include "flights.h"

int main(void) {
    FlightQueue q;
    initQueue(&q);
    
    Flight f1 = {1, "Manila", "Cebu", {8,30}, {10,15}};
    Flight f2 = {2, "Cebu", "Davao", {11,00}, {12,30}};
    Flight f3 = {3, "Davao", "Manila", {14,45}, {16,30}};

    printf("Enqueuing flights...\n");
    enqueueFlight(&q, f1);
    enqueueFlight(&q, f2);
    enqueueFlight(&q, f3);

    printf("Front of queue: Flight %d\n", peekQueue(q).id);

    printf("\nDequeuing flights:\n");
    while (!isQueueEmpty(q)) {
        Flight f = dequeueFlight(&q);
        printf("Dequeued Flight %d  %s -> %s  Dep %02d:%02d Arr %02d:%02d\n",
               f.id, f.origin, f.destination,
               f.departure_time.hours, f.departure_time.minutes,
               f.arrival_time.hours, f.arrival_time.minutes);
    }

    if (isQueueEmpty(q)) {
        printf("\nQueue is now empty.\n");
    }

    return 0;
}