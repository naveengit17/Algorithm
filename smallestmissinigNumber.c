#include <stdio.h>
#include<stdlib.h>
int main() {
	int t;
	scanf("%d",&t);
	while(t--){
	    int n;
	    scanf("%d",&n);
	    int ar[n+1];
	    int k=1;
	    for(int i=0;i<n;i++){
	        int a;
	        scanf("%d",&a);
	        if(a > 0) ar[k++] = a;
	        
        }
	    int ans = k;
	    for(int i=1;i<k;i++){
	        if(abs(ar[i]) < k ) ar[abs(ar[i]) ] = -abs(ar[abs(ar[i]) ]);
	    }
	    for(int p=1;p<k;p++){
	        if(ar[p] > 0) {
	            ans = p;
	            break;
	        }
	    }
	    printf("%d\n",ans);
	}
    return 0;
}