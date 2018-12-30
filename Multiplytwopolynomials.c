#include<stdio.h>
#include<stdlib.h>

struct node{
    int a,b;
};

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        int m,n;
        scanf("%d %d",&m,&n);
        struct node  ar[m];
        struct node  br[n];
        struct node  temp[n*m];
        int k = m-1;
        for(int i=0;i<m;i++){
            int a1;
            scanf("%d",&a1);
            ar[i].a = a1;
            ar[i].b = k--;
        }
        k = n-1;
        for(int i=0;i<n;i++){
            int a;
            scanf("%d",&a);
            br[i].a = a;
            br[i].b = k--;
        }
        k = 0;
        for(int i=0;i<m;i++){
            struct node  ptr = ar[i];
            for(int j=0;j<n;j++){
                temp[k].a = ptr.a * br[j].a;
                temp[k].b = ptr.b + br[j].b;
                k++;
            }
        }
        int ans[n+m-1];
        for(int i=0;i<n+m-1;i++) ans[i] = 0;
        k = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int a = temp[k].a;
                int b = temp[k].b;
                k++;
                ans[b] +=a;
            }
        }
        printf("\n");
        for(int i=n+m-2;i>=0;i--){
            printf("%d ",ans[i]);
        }
        printf("\n");
    }
}