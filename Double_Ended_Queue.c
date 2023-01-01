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

void EnqueueR(struct Queue *q,int val){
    if(isFull(q)){
        printf("Queue Overflow");
    }
    else{
        q->r=q->r+1;
        q->arr[q->r]=val;
    }
}
void EnqueueF(struct Queue *q,int val){
    if(isFull(q)){
        printf("Queue Overflow");
    }
    else{
        q->arr[q->f]=val;
        q->f=q->f-1;
    }
}

int DequeueF(struct Queue *q){
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

int DequeueR(struct Queue *q){
    int a=-1;
    if(q->f==q->r){
        printf("Queue Underflow");
    }
    else{
        a=q->arr[q->r];
        q->r--;
    }
    return a;
}

int main(){
    struct Queue q;
    q.size=10;
    q.f=-1;
    q.r=-1;
    q.arr=(int *)malloc(q.size*sizeof(int));
    EnqueueR(&q,10);
    EnqueueR(&q,20);
    EnqueueR(&q,30);
    EnqueueF(&q,40);
    printf("%d\n",DequeueR(&q));
    printf("%d\n",DequeueF(&q));
    printf("%d\n",DequeueF(&q));
    printf("%d\n",DequeueF(&q));
    return 0;
}

