#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};

void Traverse(struct Node * head){
    struct Node * ptr=head;
    do{
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }while(ptr!=NULL);
    printf("\n\n");
    do{
        printf("%d\n",ptr->data);
        ptr=ptr->prev;  
    }while(ptr!=NULL);
}

int main(){
    struct Node * head=(struct Node *)malloc(sizeof(struct Node));
    struct Node * second=(struct Node *)malloc(sizeof(struct Node));
    struct Node * third=(struct Node *)malloc(sizeof(struct Node));
    struct Node * fourth=(struct Node *)malloc(sizeof(struct Node));

    head->data=20;
    head->prev=NULL;
    head->next=second;

    second->data=30;
    second->prev=head;
    second->next=third;

    third->data=40;
    third->prev=second;
    third->next=fourth;

    fourth->data=50;
    fourth->next=NULL;
    fourth->prev=third;

    Traverse(head);
}