#include <stdio.h>
#include<stdlib.h>
#include<queue>

using namespace std;

struct node{
    int a,b,s;
};
/*
int top = -1,rear = -1;
struct node * queue[100000];

void push(struct node * temp ){
    if(top < 0) top++;
    queue[++rear] = temp;
}

struct node * pop(){
    return queue[top++];
}
*/
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
	    queue<struct node*> Q;
	    Q.push(temp);
	    visit[0][0] = 1;
	    int ans = -1;
	    while(!Q.empty()){
	        struct node * temp = Q.front();
			
	        if(temp->a == x && temp->b == y){
	            ans = temp->s;
	            break;
	        }

	        Q.pop();
			int i = temp->a;
			int j = temp->b;
	        if(visit[i][j + 1 ] == 0 && ar[i][j+1] == 1 && j + 1 < m){
	            struct node * ptr = getNode(i,j+1,temp->s + 1);
	            visit[i][j + 1 ] = 1;
	            Q.push(ptr);
	        }

	        if(!visit[i+1][j] && ar[i+1][j] == 1 && i +1 < n){
	            struct node * ptr = getNode(i +1,j,temp->s + 1);
	            visit[i+1][j] = 1;
	            Q.push(ptr);
	        }

	        if(!visit[i-1][j] && ar[i-1][j] == 1 && i -1 >= 0){
	            struct node * ptr = getNode(i -1,j,temp->s + 1);
	            visit[i-1][j] = 1;
	            Q.push(ptr);
	        }

	        if(visit[i][j - 1] == 0 && ar[i][j-1] == 1 && j -1 >= 0){
	            struct node * ptr = getNode(i,j -1,temp->s + 1);
	            visit[i][j - 1] = 1;
	            Q.push(ptr);
	        }
	    }

	    printf("%d\n",ans);
	}
	return 0;
}
/*
0 1 1 1 1 0 0 0 1 1 1 1 0 
0 0 0 0 1 1 1 0 1 0 1 1 0 
0 1 0 1 0 1 0 1 0 1 1 0 0 
0 1 1 0 1 1 0 1 1 1 0 1 1 
0 1 0 1 1 0 0 1 1 0 0 0 0 
0 1 1 1 1 0 0 1 0 0 0 0 1 
0 1 0 1 0 0 0 0 1 1 0 1 0 
1 0 1 1 0 1 1 1 0 0 1 1 1 
1 1 0 1 0 0 0 0 1 0 0 1 0 
1 0 0 1 0 0 1 1 1 1 1 0 0 
1 1 0 0 0 1 1 0 1 0 0 1 0 
1 0 1 0 0 0 0 1 1 1 1 0 0 
0 1 1 1 0 1 0 0 1 0 1 1 1 
0 1 1 0 1 1 0 0 1 0 1 0 1 
0 1 0 1 1 1 0 1 0 0 0 0 0 
1 0 0 0 1 0 1 1 0 1 0 0 1 
1 1 0 1 0 1 0 1 0 0 0 0 1 
0 1 1 0 1 0 0 1 1 0 0 0 1 
0 1 1 1 1 0 0 1 0 0 0 0 1 
0 0 1 1 1 1 0 0 1 1 1 0 1
*/