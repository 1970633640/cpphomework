#include <iostream>
#include <stdio.h>
using namespace std;
int c[500000]; bool d[500000];
int main()
{
    int i,n,total,cost=0,num=0;
    cin>>n>>total;
    for(i=0;i<n;i++)scanf("%d%d",&c[i],&d[i]);c[n]=2147483647;d[n]=true;
    for(i=0;i<n;i++)
    {
        if(d[i]==false && c[i]+cost<c[i+1] && c[i]+cost<=total){cost+=c[i];num++;}
    }
    cout<<num<<"\n"<<(cost>0?total-cost:total-1)<<"\n";
    return 0;
}
