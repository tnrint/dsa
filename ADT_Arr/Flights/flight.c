#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "flights.h"

Flight createFlight(int id, char origin[], char destination[], Time depart, Time arrive){
    Flight fl;
    fl.id = id;
    strcpy(fl.origin, origin);
    strcpy(fl.destination, destination);
    fl.departure_time = depart;
    fl.arrival_time = arrive;
    
    return fl;
}

void addFlight(Flights *flight_list, Flight F){
    if(flight_list->count < flight_list->max){
        flight_list->flights[flight_list->count] = F;
        flight_list->count++;
    }
}

Flight removeFlight(Flights *flightlist, int flightid){
    int idx;
    Flight remo;
    for(int i = 0; i < flightlist->count; i++){
        if(flightlist->flights->id == flightid){
            idx = i;
        } else {
            break;
            remo.id = -1;
            return remo;
        }
    }
    int rem = idx + 1;
    remo = flightlist->flights[idx];
    for(int i = 0; i < idx - flightlist->max; i++){
        flightlist->flights[idx++] = flightlist->flights[rem++];
    }
    flightlist->count--;
    return remo;
}

void showFlights(Flights flight_list){
    printf("\n%-10s %-10s %-10s %-20s %-20s\n", "Flight ID", "Origin", "Destination", "Departure Time", "Arrival Time");
    for(int i = 0; i < flight_list.count; i++){
        printf("%-10d %-10s %-10s", flight_list.flights[i].id, flight_list.flights[i].origin, flight_list.flights[i].destination);
        displayTime(flight_list.flights[i].departure_time);
        displayTime(flight_list.flights[i].arrival_time);
    }
}

void displayFlightsInfo(Flights f){
    printf("\tFlights\n");
    printf("Flight ID\t Origin\t Destination\t Departure Time\t Arrival Time\n");
    printf("%-10d %-10s %-10s ", f.flights->id, f.flights->origin, f.flights->destination);
    displayTime(f.flights->departure_time);
    displayTime(f.flights->arrival_time);
}

void displayTime(Time t){
    printf(" %d:%d:00", t.hours, t.minutes);
}

Time createTime(int h, int m){
    Time t;
    t.hours = h;
    t.minutes = m;
    
    return t;
}