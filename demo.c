#include <stdlib.h>
#include "queue.h"

int main(void) {
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
    deq(Q);
    print_queue(Q);
    deq(Q);
    print_queue(Q);
    deq(Q);
    print_queue(Q);
    deq(Q);
    print_queue(Q);
    deq(Q);
    print_queue(Q);
    free_queue(Q);
    return 0;
}
