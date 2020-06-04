
#include "mpi.h"
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


	    int comm_sz;
	    int my_rank;

	    MPI_Init(&argc, &argv);

	    MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);

	    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);


       numbers(primeNumbersLength,  comm_sz);

       //creates a smaller array for the processes
       //each individual process does their work in it
       *smallArray(numbers);

       //we use the sequential algorithm
       //but now with the MPI commands

	    MPI_Scatter(primeNumbers, numbers, MPI_INT, smallArray, numbers, MPI_INT, 0, MPI_COMM_WORLD);

        sequential(primeNumbersLength);


	    MPI_Gather(smallArray, numbers, MPI_INT, primeNumbers, numbers, MPI_INT, 0, MPI_COMM_WORLD);

	    MPI_Finalize();

      fclose(filePointer);

      return 0;

   }
]

//numbers function
int numbers(int primeNumbersLength, int comm_sz){
int numbers = (primeNumbersLength/2)/comm_sz;
}
//void function
char *smallArray(int numbers){
char *smallArray = malloc(numbers * sizeof(int));
}


void sequential(int primeNumbersLength){}

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
}




//print them
 for(int k = 0; k < primeNumbersLength; k++) {
   if(primeNumbersLength[k]) {
     fprintf(filePointer, "%d ", k);
   }
 }
