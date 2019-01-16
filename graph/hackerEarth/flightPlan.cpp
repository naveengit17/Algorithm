#include<bits/stdc++.h>
using namespace std;

int queue1[100000];
int top = -1,rear = -1;
void push1(int d){
    if(top < 0) top++;
    queue1[++rear] = d;
 }

 int pop1(){
     return queue1[top++];
 }


int main(){
    int n,m,t,c;
    cin>>n>>m>>t>>c;
    int ar[n+1],visit[n]={0};
    for(int i=0;i<=n;i++) ar[i] = -1;
    int MAT[n+1][n+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++) 
            MAT[i][j] = 0;
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        MAT[a][b] = 1;
        MAT[b][a] = 1;
    }

    int x,y;
    cin>>x>>y;
    push1(x);
    visit[x] = 1;
    int flag=1;
    while(top<=rear && top != -1&& flag){
        int f = pop1();
        if(f == y){
            break;
        }
        for(int i=0;i<=n;i++){
            if(MAT[f][i] == 1 && visit[i]==0){
                ar[i] = f;
                visit[i] = 1;
                push1(i);
                if(i == y) flag=0;
            }
        }
    }
    
    
    int ans[n];
    int k=0;
    ans[k++] =y;
    while(ar[y] != -1){
        y = ar[y];
        ans[k++] = y;
    }
    cout<<k<<endl;
    k--;
    for(;k>=0;k--){
        cout<<ans[k]<<" ";
    }
    cout<<endl;
}