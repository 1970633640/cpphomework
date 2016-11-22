#include <iostream>
#include <stdio.h>
int x[1024];
int main()
{
    int a,b,n,r,i;
    bool flag=1;
    scanf("%d%d",&n,&r);
    for(i=0; i<n-1; ++i){scanf("%d%d",&a,&b);++x[a];++x[b];}
    if(n!=1)
        for(i=1; i<=n; ++i){if(((i!=r)&&(x[i]!=3)&&(x[i]!=1))||((i==r)&&(x[i]!=2))){flag=0;break;}}
    printf("%s\n",flag==1?"yes":"no");
    return 0;
}
