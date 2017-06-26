/*
 * This is a program which takes an integer either positive or negative as input. 
 * It will convert that integer from type int to type char. Say number -23 is
 * converted to "-23".
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* itoa(int num, char result[]);


int main(int argc, char** argv) {
	if (argc < 2) {
		printf("Usage: itoa <number>\n");
		exit(1);
	}
	// after atoi, num would be a valid int within range
	int num = atoi(argv[1]);
	char result[50];
	printf("You are going to convert int %d\n", num);
	itoa(num, result);
	printf("The converted string version of %d is '%s'\n", num, result);
	return 0;
}

char* itoa(int num, char result[]){
	/*
	 *	TODO: Write the code to implement itoa. Convert number from int type to
	 *	char type. (Hint: mind the overflow case.)
	 *
	 *
	 */
	 // Check Negative
	 int neg;
	 if (num < 0) {
	 	neg = 1;
	 }
	 int num2 = num;
	 int i;
	 i = 0;
	 while (1) { 
		num2 = num2/10;
		i++;
		if (num2 == 0)
		{
		break;
		}
	 }
	 int digits[i];
	 int k;
	 int nums2 = num;
	 for (k = 0; k < i; k++) {
	 	digits[i-k-1] = abs(nums2%10);
		nums2 = nums2/10;
	 }
		 
	 int j;
	 int start;
	 if (neg == 1) {
	 	result[0] = '-';
		start = 1;
	 }
	 else {
	 	start = 0;
	 }

	 for (j = start; j < i; j++)
	 {
	 	if (neg) {
	 	result[j] = digits[j-1] + '0';
	 	}
		else {
	 	result[j] = digits[j] + '0';
		}
	 }
	 if (neg) {
	 result[i] = digits[i-1] + '0';
	 }
	 result[i+1] = '\0';

	 return result;
}

