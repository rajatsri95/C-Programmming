#include <stdio.h>

int main(int argc, char *argv[])
{
	char *str1;
	str1 = argv[1];	
	str1[3] = '\0'; 
	char *str2;
	str2 = argv[2];
	str2[3] = '\0';
	
	char k;
	k = str2[1];
	str2[1] = str1[1];
	str1[1] = k;

	printf("%s\n",str1);
	printf("%s\n",str2);

	return 0;
}

