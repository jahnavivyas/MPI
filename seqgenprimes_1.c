#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>



int main (int argc, char *argv[]) {



      char* arg1 = argv[1];
      char arg2[10000] = ".txt";
      int x = strlen(arg1);
      int y = strlen(arg2);
      char *f = malloc(x + y + 1);



      FILE * filePointer;


      strcpy(f, arg1);
      strcat(f, arg2);

      filePointer = fopen(f, "w");

      if(filePointer == NULL){
        printf("Cannot create file.\n");
        exit(EXIT_FAILURE);
      }

      bool primeNumbers[atoi(argv[1])+1];


      int primeNumbersLength = sizeof(primeNumbers);


      memset(primeNumbers, true, primeNumbersLength);


      primeNumbers[0] = false;
      primeNumbers[1] = false;

      int index;

      for (index=2; index*index<=primeNumbersLength; index++)
   {
       // If prime[p] is not changed, then it is a prime
       if (primeNumbers[index] == true)
       {

           int i;
           for (i=index*index; i<=primeNumbersLength; i += index)
               primeNumbers[i] = false;
       }
   }

    //print them
   for(int k = 0; k < primeNumbersLength; k++) {
     if(primeNumbersLength[k]) {
       fprintf(filePointer, "%d ", k);
     }
   }


   fclose(filePointer);

   return 0;

}