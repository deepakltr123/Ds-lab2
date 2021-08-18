#include<stdio.h>
#include<stdlib.h>
struct circularqueue
{
    int size;
    int f;
    int r;
    int *arr;
};
int isFull(struct circularqueue* q)
{
    if((q->r+1)%q->size==q->f)
    return 1;
    else 
    return 0;
}
int isEmpty(struct circularqueue *q)
{
    if(q->r==q->f)
    return 1;
    else 
    return 0;
}
void Enqueue(struct circularqueue* q,int val)
{
    if(isFull(q))
    printf("The queue is full:\n");
    else 
    {
       q->r = (q->r+1)%q->size;
       q->arr[q->r]=val;
       printf("The enqueued element is %d\n",val);
    }
}
int Dequeue(struct circularqueue*q)
{
    int a=-1;
    if(isEmpty(q))
    printf("The queue is empty:\n");
    else 
    {
        q->f=(q->f+1)%q->size;
         a=q->arr[q->f];
    }
    return a;
}
int main()
{
    struct circularqueue *q;
    q=( struct circularqueue*)malloc( sizeof(struct circularqueue));
    q->r=0;
    q->f=0;
    q->size=4;
    q->arr=(int *)malloc(sizeof(int)*q->size);
    Enqueue(q,23);
    Enqueue(q,19);
    Enqueue(q,100);
    printf("The dequeued element is %d\n",Dequeue(q));
    printf("The dequeued element is %d\n",Dequeue(q));
    printf("The dequeued element is %d\n",Dequeue(q));
    // Enqueue(q,45);
    //  Enqueue(q,45);
    //  Enqueue(q,45);
    if(isEmpty(q))
    printf("The queue is empty:\n"); 
    if(isFull(q))
    printf("The queue is full:\n");
    
    return 0;
}