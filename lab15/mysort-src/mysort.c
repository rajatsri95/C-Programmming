#include "mysort.h"
#include <alloca.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>



/* Compare two integer numbers*/
int compareInt( void * a, void * b )
{
  return *(int*)a - *(int*) b;
}



// Compare students by name 
// Hint: use strcmp 
int compareStudentByName( void * a, void * b )
{
  Student * sa = (Student *) a;
  Student * sb = (Student *) b;

  // Please complete this function 
	
	return strcmp(sa->name,sb->name);   
}





  /* Compare students by grade first.
     return 1 if grade a is larger than grade b
     return -1 if grade a is less than grade b
     if grades are the same then 
     compare alphabetically
  */ 

int compareStudentByGrade( void * a, void * b )
{

  // Please complete this function 
	Student * sa = (Student *) a;
	Student * sb = (Student *) b;
	if (sa->grade > sb->grade)	return 1;
	else if (sa->grade < sb->grade)	return -1;
	else {
		int comp = compareStudentByName( a, b );
		return comp;
	}
  	
}




//
// Sort an array of element of any type
// it uses "compFunc" to sort the elements.
// The elements are sorted such as:
//
// if ascending != 0
//   compFunc( array[ i ], array[ i+1 ] ) <= 0
// else
//   compFunc( array[ i ], array[ i+1 ] ) >= 0
//
// See test_sort to see how to use mysort.
//
void mysort( int n,                      // Number of elements
		int elementSize,            // Size of each element
		void * array,               // Pointer to an array
		int ascending,              // 0 -> descending; 1 -> ascending
		CompareFunction compFunc )  // Comparison function.
{
	// Please complete this function

	int i;
	int j;
	if (ascending == 1) {
		for(i = 0; i < n; i++) {
			for(j = 0; j < n-i-1; j++) {
				void* a = (void* ) array+(j*elementSize);
				void* b = (void*) array+((j+1)*elementSize);
				if(compFunc(a,b) >= 0) {
					//Swap
					void* temp = malloc(elementSize);
					memcpy(temp, a, elementSize);
					memcpy(a, b, elementSize);
					memcpy(b, temp, elementSize);
					free(temp);
				}
			}		
		}
	}
	else {
		for(i = 0; i < n; i++) {
			for(j = 0; j < n-i-1; j++) {
				void* a = (void* ) array+(j*elementSize);
				void* b = (void*) array+((j+1)*elementSize);
				if(compFunc(a,b) <= 0) {
					//Swap
					void* temp = malloc(elementSize);
					memcpy(temp, a, elementSize);
					memcpy(a, b, elementSize);
					memcpy(b, temp, elementSize);
					free(temp);
				}

			}		
		}
	}
}

















