#include<stdio.h>
#include<string.h>

//Naive approach for searching of pattern
int getMatch(char patt[],char text[]){

    for(int i=0;i<strlen(text);i++){
        int j = 0;
        for(;j<strlen(patt);j++){
            if(text[i+j] != patt[j])
                break;
        }
        if(j == strlen(patt))
            return i;
    }
    return -1;
}


int main(){
    int n;
    scanf("%d",&n);
    char patt[n];
    char text[n];
    
    scanf("%s",text);
    scanf("%s",patt);
    int i = getMatch(patt,text);
    if(i != -1)
        printf("Element found at %d\n",i);
    else printf("Element not found\n");
}