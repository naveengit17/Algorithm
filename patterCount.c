#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int t;
    int N = 2005;
    scanf("%d",&t);
    while(t--){
        char ar[N];
        scanf("%s",ar);
        int ans  = 0;
        for(int i=0;i<strlen(ar)-1;i++){
            if(ar[i] == '1'){
                int temp = 0,j;
                for( j = i+1;j<strlen(ar);j++){
                    if(ar[j] == '0' ) temp++;

                    if(ar[j] == '1') {
                        if(temp == j-i-1 && temp > 0) ans++;
                        break;
                    }
                }
                
            }
        }
        printf("%d\n",ans);
    }
}