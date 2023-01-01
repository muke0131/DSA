#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr){
    if(ptr->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct stack *ptr){
    if(ptr->top==ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack *ptr,int val){
    if(isFull(ptr)){
        printf("Stack Overflow\n");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}

int pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow\n");
    }
    else{
        int val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct stack *ptr,int i){
    if(ptr->top-i+1<0){
        printf("Not a Valid Position for the stack");
        return -1;
    }
    else{
        return ptr->arr[ptr->top-i+1];
    }
}

int stack_top(struct stack *s){
    return s->arr[s->top];
}
int stack_bottom(struct stack *s){
    return s->arr[0];
}

int main(){
    struct stack *s;
    s=(struct stack *)malloc(sizeof(struct stack));
    s->size=10;
    s->top=-1;
    s->arr=(int *)malloc(s->size*sizeof(int));

    if(isEmpty(s)){
        printf("Stack is Empty\n");
    }
    else{
        printf("Stack is Not Empty\n");
    }
    push(s,6);
    push(s,7);
    push(s,8);
    push(s,9);
    push(s,10);
    push(s,11);
    push(s,12);
    push(s,13);
    push(s,14);
    push(s,15);
    push(s,16);
    push(s,17);
    if(isEmpty(s)){
        printf("Stack is Empty\n");
    }
    else{
        printf("Stack is Not Empty\n");
    }
    // printf("%d",peek(s,4));
    for(int j=1;j<=s->top+1;j++){
        printf("The value at position %d is %d\n",j,peek(s,j));
    }

    printf("%d",stack_top(s));
    printf("%d",stack_bottom(s));

    printf("%d\n",pop(s));
    printf("%d\n",pop(s));
    printf("%d\n",pop(s));
    printf("%d\n",pop(s));
    printf("%d\n",pop(s));
    printf("%d\n",pop(s));
    printf("%d\n",pop(s));
    printf("%d\n",pop(s));
    printf("%d\n",pop(s));
    printf("%d\n",pop(s));
    printf("%d\n",pop(s));
    // printf("%d\n",pop(s));
    return 0;
}