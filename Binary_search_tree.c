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

// void inorder(struct node * root){
//     if(root!=NULL){
//         inorder(root->left);
//         printf("%d ",root->data);
//         inorder(root->right);
//     }
// }
int isBST(struct node * root){
    static struct node *prev=NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data<=prev->data){
            return 0;
        }
        prev=root;
        return isBST(root->right);
    }
    else{
        return 1;
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

    printf("%d",isBST(n));
    return 0;
}