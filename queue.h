#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef int* elem;
typedef struct queue_node queue_node;
typedef struct queue queue;
typedef struct queue* queue_t;

bool is_queue_empty(queue_t Q);

queue_t queue_new();

void enq(queue_t Q, elem e);

queue_node* deq(queue_t Q);
void free_queue_node(queue_node* node);
void free_queue(queue_t Q);

#endif