#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int data)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void inorder(struct node * root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void insert(struct node * root,int key){
    struct node * prev=NULL;
    while(root!=NULL){
        prev=root;
        if(key==root->data){
            return;
        }
        else if(key<root->data){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    struct node *new=createnode(key);
    if(key<prev->data){
        prev->left=new;
    }
    else{
        prev->right=new;
    }
}

struct node * inOrderPredecesor(struct node * root){
    root=root->left;
    while (root->right!=NULL)               
    {
        root=root->right;
    }
    return root;
}

struct node * deleteNode(struct node *root,int value){
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL && root->right==NULL){
        free(root);
        return NULL;
    }
    if(value<root->data){
        root->left=deleteNode(root->left,value);
    }
    else if(value>root->data){
        root->right=deleteNode(root->right,value);
    }
    else{
        struct node * iPre=inOrderPredecesor(root);
        root->data=iPre->data;
        root->left=deleteNode(root->left,iPre->data);
    }
    return root;
}

int main()
{
    struct node *n = createnode(5);
    struct node *n1 = createnode(3);
    struct node *n2 = createnode(6);
    struct node *n3 = createnode(1);
    struct node *n4 = createnode(4);

    n->left = n1;
    n->right = n2;
    n1->left = n3;
    n1->right = n4;

    inorder(n);
    deleteNode(n,6);
    printf("\n");
    inorder(n);

    return 0;
}