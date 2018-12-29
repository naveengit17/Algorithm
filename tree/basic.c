#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int data;
    struct node * lt,*rt;
};

struct node* getNode(int data){
    struct node * temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->lt = NULL;
    temp->rt = NULL;
    return temp;
}

void inorder(struct node * root){
    if(root){
        inorder(root->lt);
        printf("%d ",root->data);
        inorder(root->rt);
    }
}

int top = -1;
char stack[100];

void push(char  data){
    stack[++top] = data;
}

char pop(){
    return stack[top--];
}

int getIndex(char * ar,int start,int end){
    for(int i=start;i<=end;i++){
        if(ar[i] == '(')
            push(ar[i]);
        else if(ar[i] == ')'){
            pop();
            if(top < 0){
                return i;
            }
        }
    }
    return -1;
}

struct node* treeFormation(char *ar , int start , int end){
    if(start > end)
        return NULL;
    struct node * root = getNode(ar[start]-'0');
    int index = -1;
    if(start + 1 <= end && ar[start+1] == '(')
        index = getIndex(ar,start+1,end);
    if(index != -1){
        root->lt = treeFormation(ar,start+2,index-1);
        root->rt = treeFormation(ar,index+2,end-1);
    }
    return root;
}

int getLevelSum(struct node * root ,int l , int k){
    static int sum = 0;
    if(root){
        if(l == k) sum += root->data;
        getLevelSum(root->lt,l+1,k);
        getLevelSum(root->rt,l+1,k);
        return sum;
    }
}

int main(){
    char ar[100] = "0(5(6()())(4()(9()())))(7(1()())(3()()))";
    printf("%s\n",ar);
    struct node * ROOT = treeFormation( ar , 0 , strlen(ar)-1);
    printf("\n");
    inorder(ROOT);
    int sum = getLevelSum(ROOT,0,0);
    printf("sum is >>  %d",sum);
}