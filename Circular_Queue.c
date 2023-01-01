#include <stdio.h>
#include <stdlib.h>

struct Circular_Queue{
    int size;
    int f;
    int r;
    int * arr;
};

void Enqueue(struct Circular_Queue *q,int val){
    if((q->r+1)%q->size==q->f){
        printf("Circular_Queue Overflow");
    }
    else{
        q->r=q->r+1;
        q->arr[q->r]=val;
    }
}

int Dequeue(struct Circular_Queue *q){
    int a=-1;
    if(q->r==q->f){
        printf("Circular_Queue Underflow");
    }
    else{
        q->f=(q->f+1)%q->size;
        a=q->arr[q->f];
    }
    return a;
}

int main(){
    struct Circular_Queue q;
    q.size=5;
    q.f=0;
    q.r=0;
    q.arr=(int *)malloc(q.size*sizeof(int));
    Enqueue(&q,45);
    Enqueue(&q,46);
    Enqueue(&q,47);
    Enqueue(&q,48);
    Enqueue(&q,49);
    printf("%d\n",Dequeue(&q));
    printf("%d\n",Dequeue(&q));
    printf("%d\n",Dequeue(&q));
    printf("%d\n",Dequeue(&q));
    printf("%d\n",Dequeue(&q));
    return 0;
}