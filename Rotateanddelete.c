#include <stdio.h>
#include<math.h>

int main() {
	int t;
	scanf("%d",&t);
	while(t--){
	    int n;
	    scanf("%d",&n);
	    int ar[n];
	    for(int i=0;i<n;i++){
	        scanf("%d",&ar[i]);
	        
	    }
	    int j = 0;
	    for(int i=0;i<n;i++){
	        if(ar[i] <= 0){
	            int temp = ar[i];
	            ar[i] = ar[j];
	            ar[j] = temp;
	            j++;
	        }
	    }
	    int size = n - j;
	    
	    
	    for(int i = j; i< n; i++){
	        if(abs(ar[i])-1 < n && ar[abs(ar[i]) -1 +j] > 0) ar[abs(ar[i]) -1+j] = -ar[abs(ar[i]) -1+j];
	    }
	    int sum = size;
	   for(int i= 0;i<size;i++){
	       if(ar[i+j] > 0){
	           sum = i+1;
	           break;
	       }
	            
	   }
	    
	    printf("%d\n",sum);
	}
	return 0;
}