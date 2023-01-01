#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};

void linkedlisttraversal(struct Node * ptr){
    while(ptr!=NULL){
    printf("Element : %d\n",ptr->data);
    ptr=ptr->next;
    }
}

// case-1
struct Node * insertAtFirst(struct Node *head,int data){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->next=head;
    ptr->data=data;
    return ptr;
}

// case-2
struct Node * insertAtIndex(struct Node *head,int data,int index){
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    struct Node *p=head;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}

// case-3
struct Node * insertAtEnd(struct Node *head,int data){
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    int i=0;
    struct Node * p=head;
    while(p->next!=NULL){
        p=p->next;
        i++;
    }
    p->next=ptr;
    ptr->next=NULL;
    return head;
}

// case-4
struct Node * insertAfterNode(struct Node * head,struct Node *prevNode,int data){
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=prevNode->next;
    prevNode->next=ptr;
    return head;
}

// Deletion in Linked List

// case1
struct Node * deleteAtFirst(struct Node * head){
    struct Node *ptr=head;
    head=head->next;
    free(ptr);
    return head;
}

struct Node * deleteAtindex(struct Node * head,int index){
    struct Node *ptr=head;
    struct Node *p=head->next;
    int i=0;
    while(i<index-1){
        ptr=ptr->next;
        p=p->next;
        i++;
    }
    ptr->next=p->next;
    free(p);
    return head;
}

struct Node * deleteAtEnd(struct Node * head){
    struct Node *ptr=head;
    struct Node *p=head->next;
    while(p->next!=NULL){
        p=p->next;
        ptr=ptr->next;
    }
    ptr->next=NULL;
    free(p);
    return head;
}

struct Node * deleteAfterNode(struct Node * head,struct Node * prevNode){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    struct Node *p=(struct Node *)malloc(sizeof(struct Node));
    ptr=head;
    p=head->next;
    while(ptr!=prevNode){
        ptr=ptr->next;
        p=p->next;
    }
    ptr->next=p->next;
    free(p);
    return head;
}

struct Node * deleteValue(struct Node * head,int value){
    struct Node *ptr=head;
    struct Node *p=head->next;
    while(p->data!=value && p->next!=NULL){
        ptr=ptr->next;
        p=p->next;
    }
    if(p->data==value){
        ptr->next=p->next;
        free(p);
    }
    return head;
}

int main(){
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;
    head=(struct Node *)malloc(sizeof(struct Node));
    second=(struct Node *)malloc(sizeof(struct Node));
    third=(struct Node *)malloc(sizeof(struct Node));
    fourth=(struct Node *)malloc(sizeof(struct Node));

    head->data=7;
    head->next=second;

    second->data=8;
    second->next=third;

    third->data=9;
    third->next=fourth;
    fourth->data=55;
    fourth->next=NULL;
    // linkedlisttraversal(head);
    // head=insertAtFirst(head,56);
    // linkedlisttraversal(head);
    // insertAtIndex(head,20,3);
    // linkedlisttraversal(head);
    // insertAtEnd(head,23);
    // linkedlisttraversal(head);
    // head=insertAfterNode(head,second,45);
    linkedlisttraversal(head);
    printf("After Deletion\n");
    // head=deleteAtFirst(head);
    // linkedlisttraversal(head);
    head=deleteValue(head,8);
    // head=deleteAtindex(head,2);
    // linkedlisttraversal(head);
    // head=deleteAtEnd(head);
    // linkedlisttraversal(head);
    // head=deleteAfterNode(head,second);
    linkedlisttraversal(head);
    return 0;
}

