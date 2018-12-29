#include<stdio.h>

int main(){
    int n,r;
    scanf("%d %d",&n,&r);
    
    for(int i=0;i<n;i++){
        int a;
        scanf("%d",&a);
        if(a >= r) printf("Good boi\n");
        else printf("Bad boi\n");
        
    }

}