//Linked Representation of binary tree

#include <stdio.h>
#include <malloc.h>

struct node{
    int data;
    struct node *left;
    struct node * right;
};

struct node * createnode(int data){
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    p->data=data;
    p->left=NULL;
    p->right=NULL;
    return p;
}

int main()
{
    // constructing the root node
    // struct node *p;
    // p=(struct node *)malloc(sizeof(struct node));
    // p->data=1;
    // p->left=NULL;
    // p->right=NULL;

    // // constructing the first node
    // struct node *p1;
    // p1=(struct node *)malloc(sizeof(struct node));
    // p->data=2;
    // p1->left=NULL;
    // p1->right=NULL;

    // // constructing the second node
    // struct node *p2;
    // p2=(struct node *)malloc(sizeof(struct node));
    // p->data=3;
    // p2->left=NULL;
    // p2->right=NULL;

    struct node * root=createnode(1);
    struct node * first=createnode(2);
    struct node * second=createnode(3);
    root->left=first;
    root->right=second;
    return 0;
}