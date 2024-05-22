#include <stdio.h>
#include <string.h>
#define max 10000

void shifttable(char p[max], int m, int alphasize, int table[max])
{
    // write your code here
    for(int i=0;i<alphasize;i++){
        table[i]=m;
    }
    for(int j=0;j<m-2;j++){
        table[p[j]-'a']=m-1-j;
    }
    
}
int horspool(char t[max], char p[max], int n, int m, int table[max])
{
    // write your code here
    // return occurrences;
    int occurrences=0;
    int i=m-1;
    while(i<n-1){
        int k=0;
        while(k<m-1 && p[m-1-k]==t[i-k]){
            k=k+1;
        }
        if(k==m){
            occurrences++;
            i++;
        }
        else{
            i=i+table[t[i]-'a'];
        }
    }
    return occurrences;
}
int main(void)
{
    char t[max], p[max];
    int table[max];
    scanf("%s", &t);
    scanf("%s", &p);
    shifttable(p, strlen(p), 26, table);
    printf("%d", horspool(t, p, strlen(t), strlen(p), table));
}