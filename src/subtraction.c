/*****************************************************************
*
* subtraction
* 
* A simple subtraction program for Lara.
*  
* 11/22/2014
* 
* To increase the difficulty, increase the modulus in the rand function
* 
*****************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char buffer[100];
char stop = 'N';
int x, y; 
int answer;
int correct = 0;
int wrong = 0;

int main () {

  // Clear the terminal (POSIX)
  printf("\e[1;1H\e[2J");

  printf ("Are you ready to play SUBTRACTION? (Y/N):"  );
  fgets (buffer, sizeof(buffer), stdin);
  printf ("\n");

  stop = buffer[0];

  if ((stop == 'N') || (stop == 'n'))
    return 0;

  while (1) {

    // Seed the random number generator with time
    srand(time(NULL));

    // Use a modulus to limit the range of rand
    x = rand() % 100;
    y = rand() % 100;

    if (x > y)  
      printf ("What is %d - %d? (or Q to quit):  ", x, y);
    else
      printf ("What is %d - %d? (or Q to quit):  ", y, x);

    fgets (buffer, sizeof(buffer), stdin);
    
    stop = buffer[0];
   
    if ((stop == 'Q') || (stop == 'q')) {
      printf("\e[1;1H\e[2J");
      printf ("  You got %d correct and %d wrong!\n", correct, wrong);
      printf ("\n\n\n\n");
      return 0;
    }

    sscanf (buffer, "%d", &answer);

    if (x > y) {
      if (answer == x - y) {
        printf ("  CORRECT!  %d - %d = %d\n", x, y, answer);
        correct++;
      }
      else {
        printf ("  WRONG!  %d - %d = %d\n", x, y, x - y);
        wrong++;
      }
    }
    else {
      if (answer == y - x) {
        printf ("  CORRECT!  %d - %d = %d\n", y, x, answer);
        correct++;
      }
      else {
        printf ("  WRONG!  %d - %d = %d\n", y, x, y - x);
        wrong++;
      }
    }

  }

  return 0; 
}
