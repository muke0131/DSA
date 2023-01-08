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

//BFS Implementation

int main()
{
    struct Queue q;
    q.size=400;
    q.f=q.r=0;
    q.arr=(int *)malloc(q.size*sizeof(int));

    int node;
    int i=1    ;
    int visited[7]={0,0,0,0,0,0,0};
    int a[7][7]={
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0},
    };
    printf("%d ",i);
    visited[i]=1;
    Enqueue(&q,i);
    while(!isEmpty(&q))
    {
        node=Dequeue(&q);
        for(int j=0;j<7;j++){
            if(a[node][j]==1 && visited[j]==0){
                printf("%d ",j);
                visited[j]=1;
                Enqueue(&q,j);
            }
        }
    }
    return 0;
}