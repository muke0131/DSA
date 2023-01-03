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

struct node * search(struct node * root , int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data==key){
        return root;
    }
    else if(root->data>key){
        return search(root->left,key);
    }
    else{
        return search(root->right,key);
    }
}

int main()
{
    struct node *n=createnode(5);
    struct node *n1=createnode(3);
    struct node *n2=createnode(6);
    struct node *n3=createnode(1);
    struct node *n4=createnode(4);

    n->left=n1;
    n->right=n2;
    n1->left=n3;
    n1->right=n4;

    struct node * p=search(n,3);
    if(p!=NULL){
        printf("Found : %d",p->data);
    }
    else{
        printf("Element Not Found");
    }
    return 0;
}