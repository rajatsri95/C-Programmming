#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "best_team.h"

// Position meanings
const char * position_name[5] = {"Point Guard",
    "Shooting Guard",
    "Small Forward",
    "Power Forward",
    "Center"};


Team * initializeTeam() {
    // TODO: malloc a new team with 0 players and _first to NULL
    Team* team = (Team*) malloc (sizeof(Team));
    team->_numOfPlayers = 0;
    int i = 0;
    for (i = 0; i < 5; i++) {
      team->_players[i] = NULL;
    }
    return team;
}

// Returns something like "02,12,3,8,5,6,4,3,Russell" from file
// Returns 1 line from file for every function call
// Second call will return second line, etc.
char * inputFile(FILE *fd) {
    char * buffer = (char *) malloc(200 * sizeof(char));
    char * bufferptr = buffer;
    *bufferptr = fgetc(fd);
    while (*bufferptr != EOF && *bufferptr != '\0' && *bufferptr != '\n') {
        bufferptr++;
        *bufferptr = fgetc(fd);
    }
    *bufferptr = '\0';
    return buffer;
}

Player * parsePlayer(char * str) {
    // TODO: malloc size of a player, add the details from string to Player type
    Player *player = (Player*) malloc(sizeof(Player));
	int n = strlen(str);	
	int pntr = 0;
	int i = 0;	
	
	char shirtNum[10];	
	for (i = 0; i < n; i++) {
		if (str[pntr] == ',') {
			break;		
		}
		else {	
			shirtNum[i] = str[pntr];
			pntr++;
		}
	}
	pntr++;
	shirtNum[i] = '\0';
	player->_shirtNum = atoi(shirtNum);

	char age[10];	
	for (i = 0; i < n; i++) {
		if (str[pntr] == ',') {
			break;		
		}
		else {	
			age[i] = str[pntr];
			pntr++;
		}
	}	
	age[i] = '\0';
	player->_age = atoi(age);
	pntr++;

	char pos[10];	
	for (i = 0; i < n; i++) {
		if (str[pntr] == ',') {
			break;		
		}
		else {	
			pos[i] = str[pntr];
			pntr++;
		}
	}	
	pos[i] = '\0';
	player->_pos = atoi(pos);
	pntr++;

	char pass[10];
	for (i = 0; i < n; i++) {
		if (str[pntr] == ',') {
			break;		
		}
		else {	
			pass[i] = str[pntr];
			pntr++;
		}
	}	
	pass[i] = '\0';
	player->_stats._pass = atoi(pass);
	pntr++;
		
	char shoot[10];
	for (i = 0; i < n; i++) {
		if (str[pntr] == ',') {
			break;		
		}
		else {	
			shoot[i] = str[pntr];
			pntr++;
		}
	}	
	shoot[i] = '\0';
	player->_stats._shoot = atoi(shoot);
	pntr++;

	char speed[10];
	for (i = 0; i < n; i++) {
		if (str[pntr] == ',') {
			break;		
		}
		else {	
			speed[i] = str[pntr];
			pntr++;
		}
	}	
	speed[i] = '\0';
	player->_stats._speed = atoi(speed);
	pntr++;
	
	char block[10];
	for (i = 0; i < n; i++) {
		if (str[pntr] == ',') {
			break;		
		}
		else {	
			block[i] = str[pntr];
			pntr++;
		}
	}	
	block[i] = '\0';
	player->_stats._block = atoi(block);
	pntr++;

	char height[10];
	for (i = 0; i < n; i++) {
		if (str[pntr] == ',') {
			break;		
		}
		else {	
			height[i] = str[pntr];
			pntr++;
		}
	}	
	height[i] = '\0';
	player->_stats._height = atoi(height);
	pntr++;

	char* name = (char*)malloc(sizeof(char)*200);	
	for (i = 0; i < n; i++) {
		if (str[pntr] == '\0') {
			break;		
		}
		else {	
			name[i] = str[pntr];
			pntr++;
		}
	}	
	name[i] = '\0';
	player->_name = name;
		
    return player;
}

void loadData(FILE * fd) {
    // TODO: load all data from file to allPlayers
    // Don't forget to free the buffer returned by inputFile
	
	allPlayers = NULL;	
	char* fileName;
    while(1) {
		fileName = inputFile(fd);
		if (fileName[0]=='\0') {
            break;
        }		
		Player *tempPlayer;
		tempPlayer = parsePlayer(fileName);
		tempPlayer->_next = allPlayers;	
		allPlayers = tempPlayer;
		free(fileName);			   
    }
    free(fileName);

}

Player * findBestPlayer(int pos) {
    // TODO: iterate through allPlayers
    // Returns the pointer to the best player for the specified pos

	int max = -1;
	Player * tempPlayer;
	tempPlayer = allPlayers;
	Player * newPlayer;	
	
	while(tempPlayer != NULL) {	
		if ((pos == 0) && (tempPlayer->_pos == 0) && (tempPlayer->_stats._pass > max)){
			max = tempPlayer->_stats._pass;
			newPlayer = tempPlayer;
		}
		if ((pos == 1) && (tempPlayer->_pos == 1) && (tempPlayer->_stats._shoot > max) ){
			max = tempPlayer->_stats._shoot;
			newPlayer = tempPlayer;
		}	
		if ((pos == 2) && (tempPlayer->_pos == 2) && (tempPlayer->_stats._speed > max) ){
			max = tempPlayer->_stats._speed;
			newPlayer = tempPlayer;
		}
		if ((pos == 3) && (tempPlayer->_pos == 3) && (tempPlayer->_stats._block > max) ){
			max = tempPlayer->_stats._block;
			newPlayer = tempPlayer;
		}
		if ((pos == 4) && (tempPlayer->_pos == 4) && (tempPlayer->_stats._height > max) ) {
			max = tempPlayer->_stats._height;
			newPlayer = tempPlayer;
		}
		tempPlayer = tempPlayer->_next;
		
	}

    return newPlayer;
}

int buildBestTeam(Team * t) {
    // TODO: utilize findBestPlayer(pos) to build the best team
    // order of players has to be PG SG SF PF C
    t->_players[0] = findBestPlayer(0);
    t->_players[1] = findBestPlayer(1);
    t->_players[2] = findBestPlayer(2);
    t->_players[3] = findBestPlayer(3);
    t->_players[4] = findBestPlayer(4);
	t->_numOfPlayers = 5;

    return 0;
}

void freePlayer(Player * p) {
    // TODO: free allocated memory in p
	free(p->_name);
	free(p);

}

void freeTeam(Team * t) {
    // TODO: free allocated memory in t, utilize freePlayer(p)
	
	Player * curr = allPlayers;
	Player * next = allPlayers->_next;
	while(next != NULL) {
		freePlayer(curr);		
		curr = next;
		next = next->_next; 
		
	}
	freePlayer(curr);		
	free(t);
}

void print(Team * t) {
    printf("=========================\n");
    printf("      The Best Team      \n");
    printf("=========================\n\n");
    int i;
    for (i = 0; i < t->_numOfPlayers; i++) {
        printf("Name     : %s\n", t->_players[i]->_name);
        printf("Age      : %d\n", t->_players[i]->_age);
        printf("Shirt #  : %d\n", t->_players[i]->_shirtNum);
        printf("Position : %s\n\n", position_name[t->_players[i]->_pos]);
    }
}
