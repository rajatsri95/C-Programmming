#include <stdio.h>
	
int main(){
	char c;
	printf("Enter a character:");


	/*Grab the next character from stdin and store it in variable c, remember to account for the newline character*/
	c = getchar();
	getchar();
	printf("The character you entered was %c\n", c);
	printf("Enter a second character:");

	/*Grab the next character from stdin and store it in c again*/
	c = getchar();
	getchar();
	printf("The character you entered was %c\n", c);
	return 0;
}
