#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
  char still_play;
  char input;
  int number;

  printf("Welcome to the High Low game...\n");
  // Main Do-While Loop for the Game
  while(1) {
    printf("Think of a number between 1 and 100 and press <enter>");
    // Waiting for user to press Enter	
    getchar();
    int min = 1;
    int max = 100;
    int mid;
    
    while(1) {
      mid = (min + max)/2;
      while(1) {
        printf("Is it higher than %d? (y/n)\n", mid);
        input = getchar();
        getchar();
        // Checking for correct input
        if ((input == 'y') || (input == 'n')) {
          break;
        }
        else {
          printf("Type y or n\n");
        }
      }
      // Checking Yes or No and redifining min and max
      if (input == 'y') {
        min = mid + 1;
        max = max;
      }  
      else if (input == 'n') {
      			max = mid;
        		min = min;
      }
      
      // BREAK condition (Number Guessed!)
      if (min == max) {
        number = min;
        printf("\n>>>>>> The number is %d \n", number);
        break;
      }
     	
    }
    
    // Checking if user wants to continue playing    
    while(1) {	
      printf("\nDo you want to continue playing (y/n)?\n");
      still_play = getchar();
      getchar();
      // Checking for wrong inputs
      if (still_play == 'n') {
        printf("Thanks for playing!!!\n");
        return 0;
      }
      else if (still_play == 'y') {
        break;
      }		      
    }     
  }	
    
    
  return 0;
}
