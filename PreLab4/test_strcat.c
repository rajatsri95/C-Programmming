#include<string.h>
#include<stdio.h>
#include<stdlib.h>
char * mystrcat(char * dest, char * src);
int main(int argc, char ** argv) {
	char dest[200];
	strcpy(dest, "Hello");
	char * src = " World!";
	mystrcat(dest, src);
	//Testing if the string dest was modified
	if (strcmp(dest, "Hello World!") != 0) {
		printf("Failed Expected Result: Hello World! Your Result: %s\n", dest); 
	}
	else printf("mystrcat Test1 Passed\n");
	strcpy(dest, "Purdue");
	src = " CS240!";
	char * b = mystrcat(dest, src);	
	//testing if the mystrcat returns a concatenated string
	if (strcmp(b, "Purdue CS240!") != 0) {
		printf("Failed Expected Result: Purdue CS240! Your Result: %s\n", b); 
	}
	else printf("mystrcat Test2 Passed\n");
}
