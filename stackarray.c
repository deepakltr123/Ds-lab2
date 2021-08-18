#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int top;
    int size;
    int *arr;
};
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
        return 1;
    else
        return 0;
}
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
        return 1;
    else
        return 0;
}
void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("stack overflow!!! %d cannot be pushed into the stack\n",val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
int pop(struct stack*ptr){
    if(isEmpty(ptr)){
        printf("stack under flow!!!");
    return -1;
    }
    else {
        int val=ptr->arr[ptr->top--];
        return val;
    }
}
int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->top = -1;
    sp->size = 10;
    sp->arr = (int *)malloc(sizeof(int) * sp->size);
    printf("stack before push operation\n");
    printf("Empty:- %d\n", isEmpty(sp));
    printf("Full:- %d\n", isFull(sp));

    push(sp, 34);
    push(sp, 90);
    push(sp, 12);
    push(sp, 21);
    push(sp, 8);
    push(sp, 100);
    push(sp, 10);
    push(sp, 79);
    push(sp, 89);
     push(sp, 45);//*******stack full
    //  push(sp, 67);********stack overflow

    printf("stack after push operation:\n");
    printf("Empty:- %d\n", isEmpty(sp));
    printf("Full:- %d\n", isFull(sp));

    printf("popped %d from the stack\n",pop(sp));
    printf("popped %d from the stack\n",pop(sp));
    printf("popped %d from the stack\n",pop(sp));
    printf("popped %d from the stack\n",pop(sp));
    
    return 0;
}