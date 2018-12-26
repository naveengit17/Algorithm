#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * lt , * rt;
};

struct node * getNode(int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp -> data = data;
    temp->lt = NULL;
    temp->rt = NULL;
    return temp;
}

// fuction to implement insertion of BST
void insert(struct node * root, int data){
    int flag = 0;
    struct node * ptr; 
    while(flag == 0 && root != NULL){
        if(root->data > data) {
            ptr = root;
            root = root->lt;
        }
        else if(root->data == data) flag = 1;
        else {
            ptr = root;
            root = root->rt; 
        } 
    }
    if(root == NULL){
        if(data < ptr->data) ptr -> lt = getNode(data);
        else ptr -> rt = getNode(data);
    }
}

void inorder(struct node* root){
    if(root){
        inorder(root->lt);
        printf("%d  ",root->data );
        inorder(root->rt);
    }
}

//search iten in BST
int search(struct node * root , int data){
    int flag = 0;
    while(flag == 0 && root ){
        if (root->data > data)
            root = root->lt;
        else if (root -> data == data ) flag = 1;
        else root = root -> rt;
    }
    if(flag ) return 1;
    else return 0;
}
// Function to get successor node

struct node * getSucc(struct node* root){
    root = root->rt;
    while(root -> lt != NULL)
        root = root->lt;
    
    return root;
}

//Deletion in BST
void BST(struct node * root , int data){
    int flag = 0;
    struct node * ptr ;
    while(flag == 0 && root){
        if(root->data > data) ptr = root , root = root->lt;
        else if (root->data == data) flag = 1;
        else ptr = root , root = root->rt;
    }
    int type;
    if(root->lt == NULL && root->rt ==NULL ) type = 1;
    else if(root->lt && root->rt) type = 3;
    else type = 2;

    if(type == 1){
        if(ptr -> lt == root) ptr->lt = NULL;
        else ptr->rt = NULL;
    }else if(type == 2){
        if (ptr-> lt == root){
            if(root->rt == NULL) ptr->lt = root->lt;
            else ptr->lt = root->rt;
        }else{
            if(root->rt == NULL) ptr->rt = root->lt;
            else ptr->rt = root->rt;
        }
    }else{
        struct node * succ = getSucc(root);
        int item = succ->data;
        BST(root,item);
        root->data = item;
    }
}


int main(){
    int ar[12] = {1,9,8,7,6,5,4,3,2,0 ,89 ,35};
    int i = 0;
    struct node * ROOT = getNode(ar[i++]);
    for(;i<12;i++){
        insert(ROOT,ar[i]);
    }
    inorder(ROOT);
    printf("\n");
    if(search(ROOT,90))
        printf("Element is present\n");

    BST(ROOT,1);
    inorder(ROOT);
}