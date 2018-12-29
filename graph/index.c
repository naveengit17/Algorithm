#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * lt;
};

struct adlist{
    struct node* head;
};

struct Head{
    int vertex;
    struct adlist * arr;
};

struct node * getNode(int data){
    struct node * temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->lt = NULL;
    return temp;
}

struct Head * createGraph(int v){
    struct Head * graph = (struct Head*)malloc(sizeof(struct Head));
    graph->vertex = v;
    graph->arr = (struct adlist*)malloc( v * sizeof(struct adlist));
    for(int i=0;i<v;i++){
        graph->arr[i].head = NULL;
    }
    return graph;
}

void push1(struct Head * graph,int st ,int end){
    struct node * temp = getNode(end);
    temp->lt = graph->arr[st].head;
    graph->arr[st].head = temp;
    temp = getNode(st);
    temp->lt = graph->arr[end].head;
    graph->arr[end].head = temp;
}

int queue[100];
int top = -1,rear = -1;
void push_queue(int temp){
    if(top < 0) top++;
    queue[++rear] = temp;
}

int  pop(){
    return queue[top++];
}

//BFS traversal
void BFS(struct Head * graph,int s){
    int visit[graph->vertex];
    for(int i=0;i<graph->vertex;i++) visit[i] = 0;
    push_queue(s);
    visit[s] = 1;
    while(top <= rear && top != -1){
        int t = pop();
        printf("%d ",t);
        struct node * temp = graph->arr[t].head;
        while(temp){
            if(visit[temp->data] == 0){
                push_queue(temp->data);
                visit[temp->data] = 1;
            }
                
            temp = temp->lt;
        }
    }
}

//DFS traversal

void DFS(struct Head * graph ,int * visit,int data){
    visit[data] = 1;
    printf("%d ",data);
    struct node * temp = graph->arr[data].head;
    while(temp){
        if(visit[temp->data] == 0)
            DFS(graph,visit,temp->data);
        temp = temp->lt;
    }
}

int main(){
    int edge = 7;
    struct Head * graph = createGraph(5);
    for(int i=0;i<edge;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        push1(graph,a,b);
    }

    for(int i=0;i<graph->vertex;i++){
        struct node * temp = graph->arr[i].head;
        printf("%d  >  ",i);
        while(temp){
            printf("%d ",temp->data);
            temp = temp->lt;
        }
        printf("\n");
    }
    printf("starting BFS...\n");
    BFS(graph,0);
    
    int visit [graph->vertex];
    for(int  i=0;i<graph->vertex;i++) visit[i] = 0;
    printf("starting DFS...\n");
    DFS(graph,visit,0);
}