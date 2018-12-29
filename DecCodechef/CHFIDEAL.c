#include<stdio.h>

int main(){
    int x;
    printf("3\n");
    fflush(stdout);
    scanf("%d",&x);
    if(x == 2)
        printf("1\n"),fflush(stdout);
    else printf("2\n"),fflush(stdout);
    
}