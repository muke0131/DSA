#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
}*f,*r;

void linkedlisttraversal(struct Node * ptr){
    while(ptr!=NULL){
    printf("Element : %d\n",ptr->data);
    ptr=ptr->next;
    }
}

void Enqueue(int val){
    struct Node *n=(struct Node *)malloc(sizeof(struct Node));
    if(n==NULL){
        printf("Queue is FULL");
    }
    else{
        n->data=val;
        n->next=NULL;
        if(f==NULL){
            f=n;
            r=n;
        }
        else{
            r->next=n;
            r=n;
        }
    }
}

int Dequeue(){
    int a=-1;
    struct  Node *ptr=f;
    if(f==NULL){
        printf("Queue is Empty");
    }
    else{
        f=f->next;
        a=ptr->data;
        free(ptr);
    }
    return a;
}

int main()
{
    f=NULL;
    r=NULL;
    linkedlisttraversal(f);
    Enqueue(34);
    Enqueue(35);
    Enqueue(36);
    linkedlisttraversal(f);
    printf("Dequeue Element:%d\n",Dequeue());
    printf("Dequeue Element:%d\n",Dequeue());
    printf("Dequeue Element:%d\n",Dequeue());
    return 0;
}