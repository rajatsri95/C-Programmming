#include<stdio.h>
#include<stdlib.h>
//Argv[1] is the integer Argv[2] is the index
int get_bit_at(int number, int index);
int main(int argc, char ** argv) {
	int num = atoi(argv[1]);
	int index = atoi(argv[2]);
	printf("%d\n", get_bit_at(num, index));
}	
int get_bit_at(int number, int index) {
	
}
