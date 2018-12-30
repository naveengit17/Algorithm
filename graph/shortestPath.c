#include <stdio.h>
#include<stdlib.h>

struct node{
    int a,b,s;
};

int top = -1,rear = -1;
struct node * queue[100000];

void push(struct node * temp ){
    if(top < 0) top++;
    queue[++rear] = temp;
}

struct node * pop(){
    return queue[top++];
}

struct node* getNode(int a,int b,int s){
    struct node * temp = (struct node*)malloc(sizeof(struct node));
    temp->a = a;
    temp->b = b;
    temp->s = s; 
    return temp;
}
int main() {
	//code
	int t;
	scanf("%d",&t);
	while(t--){
	    int n,m;
	    scanf("%d %d",&n,&m);
	    int ar[n][m];
	    int visit[n][m];
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++) {
	            scanf("%d",&ar[i][j]);
	            visit[i][j] = 0;
	        }
	    }
	    int x,y;
	    scanf("%d %d",&x,&y);
	    struct node * temp = (struct node*)malloc(sizeof(struct node));
	    temp->a = 0;
	    temp->b = 0;
	    temp->s = 0;
	    push(temp);
	    visit[0][0] = 1;
	    int ans = -1;
	    while(top <= rear && top != -1){
	        struct node * temp = pop();
            printf("%d %d %d\n",temp->a ,temp->b,temp->s);
	        if(temp ->a == x && temp->b == y) {
	            ans = temp->s;
	            break;
	        }
	        if(visit[temp->a][temp->b + 1 ] == 0 && ar[temp->a][temp->b+1] == 1 && temp->b + 1 < n){
	            struct node * ptr = getNode(temp->a,temp->b+1,temp->s + 1);
	            visit[temp->a][temp->b + 1 ] == 1;
	            push(ptr);
	        }
	        if(visit[temp->a+1][temp->b] == 0 && ar[temp->a+1][temp->b] == 1 && temp -> a +1 < m){
	            struct node * ptr = getNode(temp->a +1,temp->b,temp->s + 1);
	            visit[temp->a+1][temp->b] == 1;
	            push(ptr);
	        }
	        if(visit[temp->a-1][temp->b] == 0 && ar[temp->a-1][temp->b] == 1 && temp->a -1 >= 0){
	            struct node * ptr = getNode(temp->a -1,temp->b,temp->s + 1);
	            visit[temp->a-1][temp->b] == 1;
	            push(ptr);
	        }
	        if(visit[temp->a][temp->b - 1] == 0 && ar[temp->a][temp->b-1] == 1 && temp->b -1 >= 0){
	            struct node * ptr = getNode(temp->a,temp->b -1,temp->s + 1);
	            visit[temp->a][temp->b - 1] == 1;
	            push(ptr);
	        }
	    }
	    printf("%d\n",ans);
	}
	return 0;
}