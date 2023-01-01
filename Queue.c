#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int size;
    int f;
    int r;
    int * arr;
};

int isEmpty(struct Queue *q){
    if(q->f==q->r){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct Queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

void Enqueue(struct Queue *q,int val){
    if(isFull(q)){
        printf("Queue Overflow");
    }
    else{
        q->r=q->r+1;
        q->arr[q->r]=val;
    }
}

int Dequeue(struct Queue *q){
    int a=-1;
    if(q->f==q->r){
        printf("Queue Underflow");
    }
    else{
        q->f++;
        a=q->arr[q->f];
    }
    return a;
}

int main(){
    struct Queue q;
    q.size=10;
    q.f=-1;
    q.r=-1;
    q.arr=(int *)malloc(q.size*sizeof(int));
    Enqueue(&q,10);
    Enqueue(&q,20);
    Enqueue(&q,30);
    printf("%d\n",Dequeue(&q));
    printf("%d\n",Dequeue(&q));
    return 0;
}

