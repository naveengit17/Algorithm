#include<iostream>
#include<utility>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
using namespace std;
int main()
{
    
    int n,i,x,j,f=1,ans=0;
    string string1,string2,s1,s2;
    cin>>n;
    map<string,bool>visited;
    vector<int>v(n);
    for(i=0;i<n;i++)
    {
        cin>>x;
        v[i]=x;
    }
    
   for(i=0;i<n;i++)
   {
      string1+=to_string(v[i]);
   }
   
   sort(v.begin(),v.end());
   
   for(i=0;i<n;i++)
   {
      string2+=to_string(v[i]);
   }
   
   queue<pair<string,int>>q;
   pair<string,int>p;
   q.push(make_pair(string1,0));
   visited[string1]=true;
   if(string1==string2)
   {
       f=0;
       ans=0;
   }
   while((!q.empty())&&(f==1))
   {
       p=q.front();
       q.pop();
       s1=p.first;
       for(j=2;j<=n;j++)
       {
           s2=s1;
           reverse(s2.begin(),s2.begin()+j);
           cout<<s2<<endl;
           if(s2==string2)
           {
               f=0;
               ans=p.second+1;
               break;
           }
           int l=p.second+1;
           if(visited[s2]!=true)
          {q.push(make_pair(s2,l));
          visited[s2]=true;}
       }
   }
  cout<<ans;
}