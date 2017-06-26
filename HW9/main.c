#include <stdio.h>
#include "Airport_Manager.h"

int main() {

	createAirportArray();
			
	char codes[5][4] = {"ATL", "ORD", "FWA", "LGA", "IND"};
	int i = 0;
	Airport * airport[5];;

	while(i !=5) {
		airport[i] = createAirport(codes[i]);
		int add = addAirport(airport[i]);
		//printf("Add Check : %d\n",add); 
		i++;
	}	

	printAirports();

	int dest[12];
	dest[0] = addDestination(airport[0], airport[1]);
	dest[1] = addDestination(airport[0], airport[2]);
	dest[2] = addDestination(airport[0], airport[3]);
	dest[3] = addDestination(airport[0], airport[4]);
	dest[4] = addDestination(airport[1], airport[2]);
	dest[5] = addDestination(airport[1], airport[4]);
	dest[6] = addDestination(airport[2], airport[1]);
	dest[7] = addDestination(airport[2], airport[3]);
	dest[8] = addDestination(airport[3], airport[2]);
	dest[9] = addDestination(airport[3], airport[4]);
	dest[10] = addDestination(airport[3], airport[1]);
	dest[11] = addDestination(airport[4], airport[3]);
	int m = 0;
	/*
	for(m = 0; m < 12; m++) {
		printf("Printing Destinations:%d\n", dest[m]);	
	}
	*/	
	int check[5];
	check[0] = hasOneStopFlight(airport[0], airport[2]);
	check[1] = hasOneStopFlight(airport[1], airport[3]);
	check[2] = hasTwoStopFlight(airport[3], airport[2]);
	check[3] = hasTwoStopFlight(airport[3], airport[0]);
	check[4] = hasTwoStopFlight(airport[4], airport[2]);
	
	/*
	int n = 0;
	for(n = 0; n < 5; n++) {
		printf("Printing Checks:%d\n", check[n]);	
	}
	*/		

	freeAllAirports();
	    
	return 0;
}
