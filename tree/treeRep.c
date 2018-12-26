#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node * lt , * rt;
};

struct node * getNode(int data){
    struct node* temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->lt = NULL;
    temp->rt = NULL;
    return temp;
}

// Inorder traversal
void inorder(struct node* root){
    if(root){
        inorder(root->lt);
        printf("%d  ",root->data);
        inorder(root->rt);
    }
}

//Preorder traversal
void preorder(struct node* root){
    if(root){
        printf("%d  ",root->data);
        preorder(root->lt);
        preorder(root->rt);
    }
}

//postorder traversal
void postorder(struct node* root){
    if(root){
        postorder(root->lt);
        postorder(root->rt);
        printf("%d  ",root->data);
    }
}

// search node in tree
struct node* findNode(struct node* root,int data){
    if(root == NULL || root-> data == data)
        return root;

    struct node * left = findNode(root->lt,data);
    if(left) 
        return left;
    struct node * right = findNode(root->rt ,data);
    if(right)
        return right;
    
    return NULL;
}

struct node * findParrent(struct node* root, struct node * parrent ,int data){
    if(root == NULL || root->lt == NULL && root->rt == NULL) 
        return NULL;
    

    if( root ->lt ? root -> lt-> data  : -1  == data || root->rt ? root ->rt -> data : -1 ==  data){
        parrent = root;
        return parrent;
    }
        
    
    struct node * left = findParrent(root->lt , parrent ,data);
    if(left)
        return left;
    struct node *right = findParrent(root->rt , parrent ,data);

    if(right)
        return right;

    return NULL;
    
}

int main(){
    struct node * ROOT = getNode(1);
    ROOT->lt = getNode(2);
    ROOT->rt = getNode(3);
    ROOT->lt->lt = getNode(4);
    ROOT->lt->rt = getNode(5);
    ROOT->rt->lt = getNode(6);
    ROOT->rt->rt = getNode(7);
    ROOT->rt->lt->rt = getNode(10);
    ROOT->lt->rt->rt = getNode(11);
    inorder(ROOT);
    printf("\n");
    preorder(ROOT);
    printf("\n");
    postorder(ROOT);
    printf("\n");

    struct node * tmp = findNode(ROOT,2);
    printf("searched node is  -->>   %d\n",tmp->data);
}