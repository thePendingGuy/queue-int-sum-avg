// Queues ADT Type Definitions
typedef struct node {
  void* dataPtr;
  struct node* next;
} QUEUE_NODE;

typedef struct {
  QUEUE_NODE* front;
  QUEUE_NODE* rear;
  int count;
} QUEUE;

// Prototype Declarations
QUEUE* createQueue( void );
QUEUE* destroyQueue( QUEUE* queue );

bool dequeue( QUEUE* queue, void** itemPtr );
bool enqueue( QUEUE* queue, void* itemPtr );
bool queueFront( QUEUE* queue, void** itemPtr );
bool queueRear( QUEUE* queue, void** itemPtr );
int queueCount( QUEUE* queue );

bool emptyQueue( QUEUE* queue );
bool fullQueue( QUEUE* queue );
// End of Queue ADT Definitions

/*
  === createQueue ===
  Allocates memory for the queue head node from dynamic memory
  and returns  its address to the caller.
    Pre     nothing
    Post    head has been allocated and initialized
    Return  head if sucessfull; null if overflow
*/
QUEUE* createQueue( void ) {
  // Local Definitions
  QUEUE* queue;

  // Statements
  queue = (QUEUE*)malloc( sizeof(QUEUE) );
  if( queue ) {
    queue->front = NULL;
    queue->rear = NULL;
    queue->count = 0;
  }// end if

  return queue;
}// end createQueue

/*
  === enqueue ===
  This algorithm inserts data into a queue.
  Pre     queue has been created
  Post    data have been inserted
  Return  true if sucessfull, false if overflow
*/
bool enqueue( QUEUE* queue, void* itemPtr ) {
  // Local definitons
  QUEUE_NODE* newPtr;

  // Statements
  if( !(newPtr = (QUEUE_NODE*)malloc(sizeof(QUEUE_NODE))) ) {
    return false;
  }// end if

  newPtr->dataPtr = itemPtr;
  newPtr->next = NULL;

  if( queue->count == 0 ) {
    // Inserting into null queue
    queue->front = newPtr;
  } else {
    queue->rear->next = newPtr;
  }// end if/else

  (queue->count)++;
  queue->rear = newPtr;

  return true;
}// end enqueue

/*
  === dequeue ===
  This Algorithm deletes a node form the queue.
  Pre     queue has been created
  Post    data pointer to queue front returned and
          front element delted and recycled.
  Return  true if successul; false if underflow
*/
bool dequeue( QUEUE* queue, void** itemPtr ) {
  // Local Definitions
  QUEUE_NODE* deleteLoc;

  // Statements
  if( !queue->count ) {
    return false;
  }// end if

  *itemPtr = queue->front->dataPtr;
  deleteLoc = queue->front;
  if( queue->count == 1 ) {
    // Deleting only item in queue
    queue->rear = queue->front = NULL;
  } else {
    queue->front = queue->front->next;
  }// end if/else

  (queue->count)--;
  free( deleteLoc );

  return true;
}// end dequeue

/*
  === queueFront ===
  This algorithm retrieves data at front of the queue without
  changing the queue contents.
    Pre     queue is pointer to an initializes queue
    Post    itemPtr passed back to caller
    Return  true if successful; false if underflow
*/
bool queueFront( QUEUE* queue, void** itemPtr ) {
  // Statements
  if( !queue->count ){
    return false;
  } else {
    *itemPtr = queue->front->dataPtr;
    return true;
  }// end if/else
}// end queueFront

/*
  === queueRear ===
  Retrieves data at the rear of the rear of the queue
  without changing the queue contents.
  Pre     queue is pointer to initialized queue
  Post    Data passed back to caller
  Return  return true if successful; false if underflow
*/
bool queueRear( QUEUE* queue, void** itemPtr ) {
  // Statements
  if( !queue->count ) {
    return true;
  } else {
    *itemPtr = queue->rear->dataPtr;
    return false;
  }// end if/else
}// end queueRear

/*
  === emptyQueue ===
  This algorithm checks to see if queue is empty.
  Pre     queue is a pointer to a queue head node
  Return  true if empty; false if queue has data
*/
bool emptyQueue( QUEUE* queue ) {
  // Statements
  return ( queue->count == 0 );
}// end emptyQueue

/*
  === fullQueue ===
  This algorithm checks to see if queue is full. It
  is full if memory cannot be allocated for next node.
  Pre     queue is a pointer to a queue head node
  Return  true if full; false if room for a node
*/
bool fullQueue( QUEUE* queue ) {
  // Local Definitions
  QUEUE_NODE* temp;

  // Statements
  temp = ( QUEUE_NODE* )malloc( sizeof(*(queue->rear)) );
  if( temp ) {
    free( temp );
    return true;
  }// end if
  // Heap full
  return false;
}// end fullQueue

/*
  === queueCount ===
  Returns the number of elemets in the queue.
  Pre     queue is pointer to the queue head node
  Return  queue count
*/
int queueCount( QUEUE* queue ) {
  // Statements
  return queue->count;
}// end queueCount

/*
  === destroyQueue ===
  Deletes all data from a queue and recycles its memory. then deletes &
  recycles queue head pointer.
  Pre     Queue is a valid queue
  Post    All data have been deleted and recycled
  Return  null pointer
*/
QUEUE* destroyQueue( QUEUE* queue ) {
  // Local Definitions
  QUEUE_NODE* deletePtr;

  // Statetments
  if( queue ) {
    while( queue->front != NULL ) {
      free( queue->front->dataPtr );
      deletePtr = queue->front;
      queue->front = queue->front->next;
      free( deletePtr );
    }// end while
    free( queue );
  }// end if

  return NULL;
}// end destroyQueue
