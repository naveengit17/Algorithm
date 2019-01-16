#include<stdio.h>
#include<stdlib.h>

struct node{
    int dest;
    int t;
    int cost;
    struct node * next;
};

struct header{
    struct node* head;
};

struct graph{
    int v;
    struct header* array;
};

struct graph * createGraph(int v){
    struct graph* root = (struct graph*)malloc(sizeof(struct graph));
    root->v = v;
    root->array = (struct header*)malloc(sizeof(struct header)*v+1);
    for(int i=0;i<=v;i++){
        root->array[i].head = NULL;
    }
    return root;
}

struct node* getNode(int t,int c){
    struct node * temp = (struct node*)malloc(sizeof(struct node*));
    temp->t = t;
    temp->cost = c;
    temp->dest = 0;
    temp->next = NULL;
    return temp;
}

struct node * heap[1000000];
int nd =-1;

void push(struct node * temp){
    heap[++nd]=temp;
    int p = nd/2;
    int i = nd;
    while(p>0 && heap[p]->cost > heap[i]->cost){
        struct node * c = heap[p];
        heap[p] = heap[i];
        heap[i] = c;
        i = p;
        p = i/2;
    }
}

struct costpath{
    int c;
    int t;
};

void heapify(int i){

    int left = 2*i +1;
    int right =2*i +2;
    int temp = i;
    if(left <= nd && heap[left]->cost <= heap[i]->cost){
        temp = left;
    }
    if(right <= nd && heap[right]->cost <= heap[i]->cost){
        temp = right;
    }
    if(temp != i){
        struct node * c = heap[temp];
        heap[temp] = heap[i];
        heap[i] = c;
        heapify(temp);
    }
}

struct node * pop(){
    struct node * temp = heap[0];
    heap[0] = heap[nd];
    nd = nd - 1;
    heapify(0);
    return temp;
}

int main(){
    int k,n,x;
    scanf("%d%d%d",&k,&n,&x);
    struct graph * root = createGraph(n);
    for(int i=0;i<x;i++){
        int a,b,t,c;
        scanf("%d%d%d%d",&a,&b,&t,&c);
        struct node * temp = getNode(t,c);
        temp->dest = b;
        temp->next = root->array[a].head;
        root->array[a].head = temp;
        temp = getNode(t,c);
        temp->dest = a;
        temp->next = root->array[b].head;
        root->array[b].head = temp;

    }
    
    int src,des;
    scanf("%d%d",&src,&des);
    struct costpath cost[n+1];
    int ar[n+1];
    int visit[n+1];
    for(int i=0;i<=n;i++) cost[i].c = 100000000,ar[i] = -1,visit[i]=0;
    struct node * temp= getNode(0,0);
    temp->dest = src;

    push(temp);
    cost[src].c = 0;
    cost[src].t = 0;

    while(nd>=0){
        struct node * temp  = pop();
        int f = temp->dest;
        if(visit[f] == 1)
            continue;
        visit[f] = 1;

        struct node * hd = root->array[f].head;
        while(hd){
            if(cost[hd->dest].c > cost[f].c + hd->cost +(hd->t +1)* k){
                cost[hd->dest].c = cost[f].c + (hd->t +1)* k +  hd->cost;
                cost[hd->dest].t = cost[f].t + (hd->t +1);
                ar[hd->dest] = f;
                push(hd);
            }
            hd = hd->next;
        }
        
    }

    int ans[n];
    int kk=0;
    ans[kk++] = des;
    int newdes = des;
    while(ar[des] != -1){
        ans[kk++] = ar[des];
        des = ar[des];
    }
    kk--;
    if(cost[newdes].c == 100000000){
        printf("Error\n");
    }else{
    for(;kk>=0;kk--){
        printf("%d",ans[kk]);
        if(kk != 0){
            printf("->");
        }
    }
    printf(" %d %d\n",cost[newdes].t-1,cost[newdes].c-k);
    }
}