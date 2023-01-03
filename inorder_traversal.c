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

void inorder(struct node * root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

int main()
{
    struct node *n=createnode(4);
    struct node *n1=createnode(1);
    struct node *n2=createnode(6);
    struct node *n3=createnode(5);
    struct node *n4=createnode(2);

    n->left=n1;
    n->right=n2;
    n1->left=n3;
    n1->right=n4;

    inorder(n);
    return 0;
}