import java.util.*;
class node{
    int a,b;
    node(int a,int b){
        this.a = a;
        this.b = b;
    }
}

class Main{
    public static void main(String arg[]){
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t > 0){
            int m,n;
            m = sc.nextInt();
            n = sc.nextInt();
            node  ar[] = new node[m];
            node  br[] = new node[n];
            node  temp[] = new node[n*m];
            int k = m-1;
            for(int i=0;i<m;i++){
                int a = sc.nextInt();
                ar[i]= new node(a,k--);
            }
            k = n-1;
            for(int i=0;i<n;i++){
                int a = sc.nextInt();
                br[i] = new node(a,k--);
            }
            k = 0;
            for(int i=0;i<m;i++){
                node  ptr = ar[i];
                
                for(int j=0;j<n;j++){
                    temp[k] = new node(0,0);
                    temp[k].a = ptr.a * br[j].a;
                    temp[k].b = ptr.b + br[j].b;
                    k++;
                }
            }
            int ans[] = new int[n+m-1];
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
            for(int i=n+m-2;i>=0;i--){
                System.out.print(ans[i]+" ");
            }
            System.out.println();
            t = t-1;
        }
    }
}