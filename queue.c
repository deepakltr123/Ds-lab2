#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};
int isEmpty(struct queue *q)
{
    if (q->f == q->r)
        return 1;
    else
        return 0;
}
int isFull(struct queue *q)
{
    if (q->r == q->size - 1)
        return 1;
    else
        return 0;
}
void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("queue overflow!!!!\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
        printf("The enqueued element is: %d\n", val);
    }
}
int dequeue(struct queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("The queue is empty!!!!\n");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
        printf("The dequeued element is %d\n", a);
    }
    return a;
}
int main()
{
    struct queue q;
    // q=(struct queue*)malloc(sizeof(struct queue));
    q.size = 4;
    q.f = -1;
    q.r = -1;
    q.arr = (int *)malloc(sizeof(int) * q.size);
    enqueue(&q, 34);
    enqueue(&q, 34);
    enqueue(&q, 34);
    enqueue(&q, 34);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    if (isEmpty(&q))
        printf("queue is empty:\n");
    if (isFull(&q))
        printf("queue is full:\n");

    return 0;
}