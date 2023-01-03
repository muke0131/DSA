#include <stdio.h>
#include <malloc.h>

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

struct node *searchIter(struct node *root, int key)
{
    while (root != NULL)
    {
        if (key == root->data)
        {
            return root;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
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

    insert(n,2);
    struct node *p = searchIter(n, 2);
    if (p != NULL)
    {
        printf("Found : %d", p->data);
    }
    else
    {
        printf("Element Not Found");
    }
    return 0;
}