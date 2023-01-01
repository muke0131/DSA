#include <stdio.h>

// int main(){
//     char exp[50];
//     scanf("%s",exp);
//     int n=sizeof(exp);
//     char stack[n];
//     int top=-1;
//     for(int i=0;i<n;i++){
//         if(exp[i]=='('){
//             top=top+1;
//             stack[top]='(';
//         }
//         else if(exp[i]==')'){
//             if(top!=-1){
//                 top=top-1;
//             }
//             else{
//                 printf("Paranthesis Mismatched\n");
//                 return 0;
//             }
//         }
//     }
//     if(top==-1){
//         printf("Paranthesis Matched\n");
//     }
//     else{
//         printf("Paranthesis Mismatched\n");
//     }
//     return 0;
// }

// Multiple Paranthesis

int main(){
    char exp[50];
    scanf("%s",exp);
    int n=sizeof(exp);
    char stack[n];
    int top=-1;
    for(int i=0;i<n;i++){
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
            top=top+1;
            stack[top]=exp[i];
        }
        else if(exp[i]==')' || exp[i]=='}' || exp[i]==']'){
            if(top!=-1 && (exp[i]==')' && stack[top]=='(') || (exp[i]=='}' && stack[top]=='{') || (exp[i]==']' && stack[top]=='[')){
                top=top-1;
            }
            else{
                printf("Paranthesis Mismatched\n");
                return 0;
            }
        }
    }
    if(top==-1){
        printf("Paranthesis Matched\n");
    }
    else{
        printf("Paranthesis Mismatched\n");
    }
    return 0;
}