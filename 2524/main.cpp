#include <iostream>
#include <stdio.h>
using namespace std;
int root[50001];
void init(int x)
{
    for(int i=1; i<=x; i++)root[i]=i;
}

int gotohead(int a)
{int temp=a;
    while(a!=root[a])a=root[a];
    while(temp!=a){int tt=root[temp];root[temp]=a;temp=tt;}
    return a;
}

void connect(int a,int b)
{
    a=gotohead(a);
    b=gotohead(b);
    if(a!=b)root[b]=a;
}

int main()
{
    int n,x,a,b,sum=1;
    while(scanf("%d%d",&x,&n) && x!=0)
    {
        init(x);
        while(n--)
        {
            scanf("%d%d",&a,&b);
            connect(a,b);
        }
        int ans=0;
        for(int i=1; i<=x; i++)if(root[i]==i)ans++;
        printf("Case %d: %d\n",sum++,ans);
    }
    return 0;
}
