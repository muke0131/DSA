#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack{
    int size;
    int top;
    char *arr;
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

int stack_top(struct stack *s){
    return s->arr[s->top];
}

int precedence(char ch){
    if(ch=='+' || ch=='-'){
        return 3;
    }
    else if(ch=='*' || ch=='/'){
        return 2;
    }
    else{
        return 0;
    }
}

int isOperator(char ch){
    if(ch=='+' || ch=='-' || ch=='/' || ch=='*'){
        return 1;
    }
    else{
        return 0;
    }
}
char * infix_to_postfix(char * infix){
    struct stack * sp=(struct stack *)malloc(sizeof(struct stack));
    sp->size=10;
    sp->top=-1;
    sp->arr=(char *)malloc(sp->size*sizeof(char));
    char * pos=(char *)malloc((strlen(infix)+1)*sizeof(char));
    int i=0,j=0;
    while (infix[i]!='\0')      
    {
        if(!isOperator(infix[i])){
            pos[j]=infix[i];
            i++;
            j++;
        }
        else{
            if(precedence(infix[i])>precedence(stack_top(sp))){
                push(sp,infix[i]);
                i++;
            }
            else{
                pos[j]=pop(sp);
                j++;
                i++;
            }
        }
    }
    while (!isEmpty(sp))
    {
        pos[j]=pop(sp);
        j++;
    }
    pos[j]='\0'    ;
    return pos;
}

int main(){
    char * infix="a-b+t/6";
    printf("Postfix is %s",infix_to_postfix(infix));
    return 0;
}