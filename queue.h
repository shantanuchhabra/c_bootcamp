/*** Interface ***/

typedef struct queue_node queue_node;
typedef struct queue_header* queue_t;

bool queue_empty(queue_t Q)

queue_t queue_new()

void enq(queue_t Q, string e)

queue_node deq(queue_t Q)