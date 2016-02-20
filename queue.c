#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

struct queue_node {
    elem data;
    struct queue_node* next;
    struct queue_node* prev;
};

struct queue {
    queue_node* front; // Points to root queue_node
    queue_node* back;
    int size;
};

bool is_queue_empty (queue_t Q) {
    if (Q == NULL) {
        fprintf(stderr, "NULL Queue.");
        exit(1);
    }
    if (Q->size == 0) {
        printf("Empty queue\n");
    }
    return (Q->size == 0);
}

queue_t queue_new() {
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

queue_node* deq(queue_t Q) {
    if (is_queue_empty(Q)) {
        return NULL;
    }
    queue_node* node = Q->front;
    Q->front->next->prev = NULL;
    Q->front = Q->front->next;
    Q->size -= 1;
    return node;
}

void free_queue_node(queue_node* node) {
    if (node == NULL) return;
    free(node->data);
    free_queue_node(node->next);
    free(node);
}

void free_queue(queue_t Q) {
    free_queue_node(Q->front);
    free(Q);
}

void print_node_data(elem data) {
    printf("%d ", *data);
}

void print_queue(queue_t Q) {
    queue_node* p = Q->front;
    while (p != Q->back) {
        print_node_data(p->data);
        p = p->next;
    }
}

int main() {
    queue_t Q = queue_new();
    int* data1 = malloc(sizeof(int)); 
    *data1 = 1;
    int* data2 = malloc(sizeof(int)); 
    *data2 = 2;
    int* data3 = malloc(sizeof(int)); 
    *data3 = 3;
    int* data4 = malloc(sizeof(int)); 
    *data4 = 42;
    enq(Q, data1);
    enq(Q, data2);
    enq(Q, data3);
    enq(Q, data4);
    print_queue(Q);
    printf("\n");
    deq(Q);
    print_queue(Q);
    printf("\n");
    deq(Q);
    print_queue(Q);
    printf("\n");
    deq(Q);
    print_queue(Q);
    printf("\n");
    deq(Q);
    print_queue(Q);
    printf("\n");
    deq(Q);
    print_queue(Q);
    return 0;
}


