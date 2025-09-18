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

typedef struct {
    Flight *flights;
    int count;
    int max;
} Flights;

Flight createFlight(); //Use flight data as parameters
void addFlight(Flights *flight_list, Flight f);
Flight removeFlight(Flights *flightlist, int flightid); // returns Flight with id -1 if not found
void showFlights(Flights flight_list);
void displayFlightInfo(Flight f); 
// display in standard time HH:MM XX
void displayTime(Time t);
Time createTime(int h, int m);

#endif