#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef int* elem;
typedef struct queue queue;
typedef struct queue* queue_t;

bool is_queue_empty(queue_t Q);

queue_t queue_new(void);

void enq(queue_t Q, elem e);

elem deq(queue_t Q);

void print_queue(queue_t Q);

void free_queue(queue_t Q);

#endif
