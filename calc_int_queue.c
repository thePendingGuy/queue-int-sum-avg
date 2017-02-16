#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queues.h"

// Protottype Statements
void fillQueue( QUEUE* );

int main( void ) {
    // Local Definitions
    int sum = 0;
    int count = 0;
    QUEUE* intq;

    // Created the numbers queue( intq )
    intq = createQueue();

    fillQueue( intq );

    while( !emptyQueue(intq) ) {
      int* dataPtr;
      dataPtr = (int*)malloc(sizeof(int));
      dequeue( intq, (void*)&dataPtr );
      sum += *dataPtr;
      printf( "%2d\n", *dataPtr);
      count++;
    }// end while

    printf( "Sum: %2d\n", sum );
    printf( "Avg: %2d\n", sum/count );

    return 0;
}// end main

/*
  === fillQueue ===
  This function generates data using rand() and places them in
  a queue.
  Pre   queue has been created
  Post  Queue filled with data
*/
void fillQueue( QUEUE* intq ) {
  // Local Definitions
  int item;
  int* dataPtr;

  // Statements
  for ( int i = 1; i <= 3; i++ ) {
    if( !(dataPtr = (int*)malloc(sizeof(int))) ) {
      printf( "Overflow in fillQueue\a\n" ), exit(100);
    }// end if
    *dataPtr = item = rand() % 51;
    printf( "%2d\n", item );
    enqueue( intq, dataPtr );
  }// end for

return;
}// end fillQueue
