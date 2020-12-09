#define pdPASS 1
#define pdFAIL 0 

#define queueUNLOCKED					( ( signed portBASE_TYPE ) -1 )
#define queueLOCKED_UNMODIFIED			( ( signed portBASE_TYPE ) 0 )

#define queueERRONEOUS_UNBLOCK			( -1 )

/* For internal use only. */
#define	queueSEND_TO_BACK				( 0 )
#define	queueSEND_TO_FRONT				( 1 )

/* Effectively make a union out of the xQUEUE structure. */
#define pxMutexHolder					pcTail
#define uxQueueType						pcHead
#define uxRecursiveCallCount			pcReadFrom
#define queueQUEUE_IS_MUTEX				0

/* Semaphores do not actually store or copy data, so have an items size of
zero. */
#define queueSEMAPHORE_QUEUE_ITEM_LENGTH ( ( unsigned portBASE_TYPE ) 0 )
#define queueDONT_BLOCK					 ( ( portTickType ) 0U )
#define queueMUTEX_GIVE_BLOCK_TIME		 ( ( portTickType ) 0U )
#define portTickType portBASE_TYPE
/* These definitions *must* match those in queue.h. */
#define queueQUEUE_TYPE_BASE				( 0U )
#define queueQUEUE_TYPE_MUTEX 				( 1U )
#define queueQUEUE_TYPE_COUNTING_SEMAPHORE	( 2U )
#define queueQUEUE_TYPE_BINARY_SEMAPHORE	( 3U )
#define queueQUEUE_TYPE_RECURSIVE_MUTEX		( 4U )

#define  portBASE_TYPE int

typedef struct QueueDefinition
{
	signed char *pcHead;				/*< Points to the beginning of the queue storage area. */
	signed char *pcTail;				/*< Points to the byte at the end of the queue storage area.  Once more byte is allocated than necessary to store the queue items, this is used as a marker. */

	signed char *pcWriteTo;				/*< Points to the free next place in the storage area. */
	signed char *pcReadFrom;			/*< Points to the last place that a queued item was read from. */

	volatile unsigned portBASE_TYPE uxMessagesWaiting;/*< The number of items currently in the queue. */
	unsigned portBASE_TYPE uxLength;		/*< The length of the queue defined as the number of items it will hold, not the number of bytes. */
	unsigned portBASE_TYPE uxItemSize;		/*< The size of each items that the queue will hold. */

	volatile signed portBASE_TYPE xRxLock;	/*< Stores the number of items received from the queue (removed from the queue) while the queue was locked.  Set to queueUNLOCKED when the queue is not locked. */
	volatile signed portBASE_TYPE xTxLock;	/*< Stores the number of items transmitted to the queue (added to the queue) while the queue was locked.  Set to queueUNLOCKED when the queue is not locked. */

    unsigned char ucQueueType;
} xQUEUE;

typedef xQUEUE * xQueueHandle;

signed char* xTaskGetCurrentTaskHandle(void);
portBASE_TYPE xQueueGiveMutexRecursive( xQueueHandle pxMutex );
signed portBASE_TYPE xQueueGenericSend( xQueueHandle pxQueue, const void * const pvItemToQueue, portTickType xTicksToWait);
static void prvCopyDataToQueue( xQUEUE *pxQueue, const void *pvItemToQueue, portBASE_TYPE xPosition );

portBASE_TYPE xQueueGiveMutexRecursive( xQueueHandle pxMutex )
{
	portBASE_TYPE xReturn;


	if( pxMutex->pxMutexHolder == xTaskGetCurrentTaskHandle() )
	{
	        (pxMutex->uxRecursiveCallCount)--;
			/* Have we unwound the call count? */
		 if( pxMutex->uxRecursiveCallCount == 0 ) 
            	 {
                	xQueueGenericSend( pxMutex, 0, queueMUTEX_GIVE_BLOCK_TIME);
			xReturn = pdPASS;
            	 }
	}
	else
	{
		/* We cannot give the mutex because we are not the holder. */
		xReturn = pdFAIL;

	}
    return xReturn;

}
/*
signed portBASE_TYPE xQueueGenericSend( xQueueHandle pxQueue, const void * const pvItemToQueue, portTickType xTicksToWait, portBASE_TYPE xCopyPosition )
{

	for(;;)
	{
		{
			if( pxQueue->uxMessagesWaiting < pxQueue->uxLength )
			{
				prvCopyDataToQueue( pxQueue, pvItemToQueue, xCopyPosition );
				break;
			}
        }
    }
    
    return pdFAIL;
}
*/
static void prvCopyDataToQueue( xQUEUE *pxQueue, const void *pvItemToQueue, portBASE_TYPE xPosition )
{
	if( pxQueue->uxItemSize == ( unsigned portBASE_TYPE ) 0 )
	{
		{
			if( pxQueue->uxQueueType == queueQUEUE_IS_MUTEX )
			{
				/* The mutex is no longer being held. */
				pxQueue->pxMutexHolder = 0;
			}
		}
	}
    (pxQueue->uxMessagesWaiting)++;
}
