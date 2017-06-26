#include "memcmp.h"
int memcmp(const void *s1, const void *s2, size_t n) {
	int i = 0;
	
	for (i = 0; i < n ; i++) {
		unsigned char* a = (unsigned char *) s1;
		unsigned char* b = (unsigned char *) s2;
		if (*a != *b) {
			if (*a > *b) return 1;
			if (*a < *b) return -1;
		}
		s1++;
		s2++;
	}
	return 0;
}
