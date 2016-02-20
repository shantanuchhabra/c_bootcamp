typedef void* elem;

typedef struct queue_node {
    elem data;
    struct queue_node* next;
    struct queue_node* prev;
} queue_node

typedef struct queue {
    queue_node* front; // Points to root queue_node
    queue_node* back;
    int size;
} queue

bool queue_empty (queue_t Q) {
    return (Q->size == 0);
}

queue_t queue_empty() {
    queue_t Q = malloc(sizeof(queue));
    queue_node* dummy = malloc(sizeof(queue_node));
    dummy->data = NULL;
    dummy->next = NULL;
    dummy->prev = NULL;
    Q->front = malloc(sizeof(queue_node));
    Q->back = malloc(sizeof(queue_node));
    Q->front = dummy;
    Q->back = Q->front;
    Q->size = 0;
    return Q;
}

void enq (queue_t Q, elem data) {
    queue_node* new_elem = malloc(sizeof(queue_node));
    new_elem->data = data;
    if (queue_empty(Q)) {
        // queue is empty
        new_elem->prev = NULL;
        new_elem->next = Q->back;
        Q->back->prev = new_elem;
        Q->front = new_elem;
    }
    else {
        // queue is not empty
        new_elem->next = Q->back;
    }
}

queue_node* deq(queue_t Q) {
    if (Q->size == 0) return NULL;
    queue_node* elem = Q->
}




