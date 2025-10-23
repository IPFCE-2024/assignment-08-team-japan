#include <stdio.h>
#include <assert.h>

#include "exercise3.h"

int main(void) {
    queue q;
initialize(&q);

    /* Law (1): After initialize(q); the queue q must be empty. */
    assert(q.count == 0 && q.front == NULL && q.rear == NULL);
    printf("Law 1 passed\n");

    /* Law (2): enqueue(x, q); y = dequeue(q); q must be same as before, and x == y. */
    initialize(&q);
    node *old_front = q.front;
    node *old_rear = q.rear;
    int old_count = q.count;

    enqueue(&q, 32);
    int y = dequeue(&q);
    assert(y == 32 && "Law 2 failed: dequeued value does not match enqueued value");
    assert(q.front == old_front && q.rear == old_rear && q.count == old_count && "Law 2 failed: queue not restored to original state after enqueue/dequeue");
    printf("Law 2 passed\n");

    /* Law (3): enqueue(x0,q); enqueue(x1,q); y0=dequeue(q); y1=dequeue(q); q same as before; x0==y0; x1==y1 */
    initialize(&q);
    int x0 = 123;
    int x1 = 234;
    enqueue(&q, x0);
    enqueue(&q, x1);

    int y0 = dequeue(&q);
    int y1 = dequeue(&q);

    assert(x0 == y0 && x1 == y1 && "Law 3 failed: FIFO");
    printf("Law 3 passed\n");

    printf("All queue law tests passed\n");
    return 0;
}