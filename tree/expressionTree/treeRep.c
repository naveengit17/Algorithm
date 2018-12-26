#include<stdio.h>
#include<stdlib.h>
struct node {
    char data;
    struct node * lt , * rt;
};

int integer[300];
struct node* stack[100];
int top = -1;

void push(struct node * temp){
    stack[++top] = temp;
}

struct node * pop(){
    return stack[top--];
}

int operand(char c){
    if(c == '+' || c == '-' || c == '*' || c == '/')
        return 0;
    return 1;
    
}

struct node* getNode(char data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->lt = NULL;
    temp->rt = NULL;
    temp->data =  data;
    return temp;
}

void inorder(struct node * root){
    if(root){
        inorder(root->lt);
        printf("%c  ",root->data);
        inorder(root->rt);
    }
}

// Evaluate expression tree
int evaluate(struct node* root){
    if(root){
        if(operand(root->data))
            return integer[root->data];
        else{
            int left = evaluate(root->lt);
            int right= evaluate(root->rt);
            if(root->data == '+') return left + right;
            if(root->data == '-') return left - right;
            if(root->data == '*') return left * right;
            if(root->data == '/') return left / right;
        }
    }
}

int main(){
    char ar[100] = "ABC*D/+#";
    integer['A'] = 2;
    integer['B'] = 3;
    integer['C'] = 4;
    integer['D'] = 6;
    printf("%s \n",ar);
    int i = 0;
    while(ar[i] != '#'){
        if(operand(ar[i])){
            struct node * temp = getNode(ar[i]);
            push(temp);
        }else{
            struct node * right = pop();
            struct node * left = pop();
            struct node * temp = getNode(ar[i]);
            temp -> lt = left;
            temp->rt = right;
            push(temp);
        }
        i++;
    }
    struct node * ROOT = pop();
    inorder(ROOT);
    printf("\n");
    //Driver function to 
    printf("%d\n",evaluate(ROOT));
}