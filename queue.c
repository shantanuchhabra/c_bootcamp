#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

typedef struct queue_node {
    elem data;
    struct queue_node* next;
    struct queue_node* prev;
} queue_node;

struct queue {
    queue_node* front; // Points to root queue_node
    queue_node* back;
    int size;
};

bool is_queue_empty (queue_t Q) {
    if (Q == NULL) {
        fprintf(stderr, "NULL Queue.\n");
        exit(1);
    }
    if (Q->size == 0) {
        printf("Empty queue\n");
    }
    return (Q->size == 0);
}

queue_t queue_new(void) {
    queue_t Q = malloc(sizeof(queue));
    queue_node* dummy = malloc(sizeof(queue_node));
    dummy->data = NULL;
    dummy->next = NULL;
    dummy->prev = NULL;
    Q->front = dummy;
    Q->back = Q->front;
    Q->size = 0;
    return Q;
}

// EXAMPLE FUNCTION HEADER COMMENT
/* enq - enqueue an elem data onto the back of queue Q
 * params: Q = pointer to queue instance
 *         data = data of type elem to enqueue
 */
void enq (queue_t Q, elem data) {
    queue_node* new_node = malloc(sizeof(queue_node));
    new_node->data = data;
    if (is_queue_empty(Q)) {
        // queue is empty
        new_node->prev = NULL;
        new_node->next = Q->back;
        Q->back->prev = new_node;
        Q->front = new_node;
    }
    else {
        // queue is not empty
        new_node->next = Q->back;
        new_node->prev = Q->back->prev;
        Q->back->prev = new_node;
        new_node->prev->next = new_node;
    }
    Q->size += 1;
}

elem deq(queue_t Q) {
    if (is_queue_empty(Q)) {
        return NULL;
    }
    queue_node* node = Q->front;
    Q->front->next->prev = NULL;
    Q->front = Q->front->next;
    Q->size -= 1;
    return node->data;
    // free(node->data);
    // free(node);
}

static void free_queue_node(queue_node* node) {
    if (node == NULL) return;
    free(node->data);
    free_queue_node(node->next);
    free(node);
}

void free_queue(queue_t Q) {
    free_queue_node(Q->front);
    free(Q);
}

static inline void print_node_data(elem data) {
    printf("%d ", *data);
}

void print_queue(queue_t Q) {
    queue_node* p = Q->front;
    while (p != Q->back) {
        print_node_data(p->data);
        p = p->next;
    }
    putchar('\n');
}


/* 
 * inline avoids overhead of function calling
 * it copies the machine code of the function and 
 * place it wherever it's called.
 * inline is slightly better than macro because
 * the subst happens after compilation and not before
 */

