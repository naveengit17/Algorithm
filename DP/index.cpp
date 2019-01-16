#include<iostream>
#include<string.h>
using namespace std;

int min(int a,int b,int c){
    if (a < b && a < c) return a;
    else if(b<a && b< c) return b;
    else return c;
}

int edit(char str1[],char str2[], int len1,int len2){
    if(len1 == 0) return len2;
    if(len2 == 0) return len1;

    if(str1[len1] == str2[len2]) return edit(str1,str2,len1-1,len2-1);

    return 1 + min(edit(str1,str2,len1-1,len2-1),edit(str1,str2,len1,len2-1),edit(str1,str2,len1-1,len2));
}

int main(){
    char str1[] = "sunday";
    char str2[] = "saturday";
    cout<<edit(str1,str2,strlen(str1)-1,strlen(str2)-1);
}