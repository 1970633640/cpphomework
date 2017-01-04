#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n,m,k;
bool x[105][105];  //a->b
int link[105];
bool vis[105];
bool f(int c)
{
    for(int i=1; i<=m; i++)
    {
        if(!vis[i] && x[c][i])
        {
            vis[i]=1;
            if(link[i]==-1 || f(link[i]) )
            {
                link[i]=c;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    while(~scanf("%d",&n) && n!=0)
    {
        scanf("%d%d",&m,&k);
        memset(x,0,sizeof(x));
        int a,b,shit;
        while(k--)
        {
            scanf("%d%d%d",&shit,&a,&b);
            if(a!=0 && b!=0)x[a][b]=1;
        }
        int ans=0;
        memset(link,-1,sizeof(link));
        for(int i=1; i<=n; i++)
        {
            memset(vis,0,sizeof(vis));
            if(f(i))ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
