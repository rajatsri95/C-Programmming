#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Airport_Manager.h"

void createAirportArray() {
	int max = 20;
	airports = (Airport **) malloc(max*sizeof(Airport));
	numAirports = 0;
	maxAirports = max;	
}

int hasOneStopFlight(Airport * start, Airport * dest) {
	if ((start == NULL) || (dest == NULL)) return -1;	
	int i;
	int num = -1;;
	for (i = 0; i < numAirports; i++) {
		if (strcmp(airports[i]->name, start->name) == 0){
			num = i;
		}
	}
	if (num == -1) {
		return -1;
	}
	int numDest = airports[num]->numDestinations;
	int j = 0;
	for (j = 0; j < numDest; j++) {
		if (strcmp(airports[num]->destinations[j]->name, dest->name) == 0)
			return 1;
	}
	return 0;	
}

int hasTwoStopFlight(Airport * start, Airport * dest) {
	if ((start == NULL) || (dest == NULL)) return -1;	
	int oneStop = hasOneStopFlight(start,dest);
	if (oneStop == 1) return 2;
	int i;
	int num = -1;;
	for (i = 0; i < numAirports; i++) {
		if (strcmp(airports[i]->name, start->name) == 0){
			num = i;
		}
	}
	if (num == -1) {
		return -1;
	}
	int numDest = airports[num]->numDestinations;
	int j = 0;
	int k = 0;
	for (j = 0; j < numDest; j++) {
		int numDest2 = airports[num]->destinations[j]->numDestinations; 
		for (k = 0; k < numDest2; k++) {
			if (strcmp(airports[num]->destinations[j]->destinations[k]->name, dest->name) == 0)
			return 1;
		}
	}
	return 0;

}

int addDestination(Airport * airport, Airport * dest) {
	// When it is invalid
	if ((airport == NULL) || (dest == NULL)) return -1;	
	int i;
	int num = -1;;
	for (i = 0; i < numAirports; i++) {
		if (strcmp(airports[i]->name, airport->name) == 0){
			num = i;
		}
	}
	if (num == -1) {
		return -1;
	}
	int numDest = airports[num]->numDestinations;
	int j = 0;
	for (j = 0; j < numDest; j++) {
		if (strcmp(airports[num]->destinations[j]->name, dest->name) == 0)
			return 0;
	}
	airports[num]->destinations[numDest] = dest; 
	airports[num]->numDestinations++;
	return 1;
}

int addAirport(Airport * airport) {
	if (airport == NULL) return -1;	
	int i = 0;
	for (i = 0; i < numAirports; i++) {
		if (strcmp(airports[i]->name, airport->name) == 0){
			return 0;
		}
	}
	if (numAirports == maxAirports) {
		maxAirports = 2 * maxAirports;
		airports = realloc(airports,maxAirports*(sizeof(Airport)));
	}
	airports[numAirports] = airport;
	numAirports++;
	return 1;
}

Airport * createAirport(const char * name) {
	if (name == NULL) 
		return NULL;	
	Airport * a = (Airport *) malloc(sizeof(Airport));
	a->name = strdup(name);
	a->numDestinations = 0;
	a->destinations = malloc(maxAirports*sizeof(Airport)); 
	return a;
}

void printAirports() {
	printf("NumberOfAirports: %d\n", numAirports);
	int i = 0;
	for (i = 0; i < numAirports; i++) {
		printf("%s\n", airports[i]->name);
	}
	printf("\n");
}

void freeAllAirports() {
	int i = 0;
	for (i = 0; i < numAirports; i++) {
		free(airports[i]->name);	
		free(airports[i]->destinations);
		free(airports[i]);
	}	
	free(airports);
}




