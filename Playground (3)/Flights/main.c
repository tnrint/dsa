#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "flights.h"

#define MAX_FLIGHTS 100
#define MAX_STR 10

int main() {
    Flights flight_list;
    flight_list.count = 0;
    flight_list.max = MAX_FLIGHTS;
    flight_list.flights = malloc(sizeof(Flight) * flight_list.max);
    if (!flight_list.flights) {
        printf("Memory allocation failed\n");
        return 1;
    }

    int choice;
    int n;
    
    do {
        printf("\nFlight Management System\n");
        printf("1. Add a flight\n");
        printf("2. Show all flights\n");
        printf("3. Remove a flight\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                printf("How many flights do you want to enter? ");
                scanf("%d", &n);

                for (int i = 0; i < n; i++) {
                    int id;
                    char origin[MAX_STR];
                    char destination[MAX_STR];
                    int dh, dm, ah, am;

                    printf("Enter flight ID: ");
                    scanf("%d", &id);

                    printf("Enter origin airport code: ");
                    scanf("%s", origin);

                    printf("Enter destination airport code: ");
                    scanf("%s", destination);

                    printf("Enter departure time (hour minute): ");
                    scanf("%d %d", &dh, &dm);

                    printf("Enter arrival time (hour minute): ");
                    scanf("%d %d", &ah, &am);

                    printf("\nDEBUG: Flight ID: %d, Origin: %s, Destination: %s, Departure: %02d:%02d, Arrival: %02d:%02d\n", id, origin, destination, dh, dm, ah, am);

                    Time depart = createTime(dh, dm);
                    Time arrive = createTime(ah, am);

                    Flight f = createFlight(id, origin, destination, depart, arrive);
                    addFlight(&flight_list, f);
                }
                break;
            case 2:
                printf("\nAll flights entered:\n");
                showFlights(flight_list);
                break;
            case 3:
                {
                    int flight_id;
                    printf("Enter flight ID to remove: ");
                    scanf("%d", &flight_id);
                    Flight removed = removeFlight(&flight_list, flight_id);
                    if (removed.id != -1) {
                        printf("Removed flight ID %d\n", removed.id);
                    } else {
                        printf("Flight with ID %d not found.\n", flight_id);
                    }
                }
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
    return 0;
}
