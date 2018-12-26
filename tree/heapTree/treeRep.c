#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int *ar,int i,int n){
    int lt = 2*i + 1;
    int rt = 2*i  +2;
    int temp = i;
    if(lt <= n && ar[lt] > ar[i]) temp = lt;

    if(rt <= n && ar[rt] > ar[temp]) temp = rt;

    if(temp != i){
        swap(&ar[i],&ar[temp]);
        heapify(ar,temp,n);
    }
}

void maxHeap(int *ar,int n){
    for(int i=n/2;i>=0;i--){
        heapify(ar,i,n);
    }
}

void heapSort(int *ar,int n){
    for(int i=n;i>0;i--){
        swap(&ar[i],&ar[0]);
        heapify(ar,0,i-1);
    }
}

int main(){
    int ar[12] = {1,2,3,4,9,7,5,0,6,8,23232,343};
    int n = sizeof(ar)/sizeof(ar[0]);
    maxHeap(ar,n-1);
    heapSort(ar,n-1);
    for(int i=0;i<n;i++)
        printf("%d ",ar[i]);
    printf("\n");

}
