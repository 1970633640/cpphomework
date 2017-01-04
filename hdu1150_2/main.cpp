#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int Map[110][110],vis[110],n,m;
int ok[110];

bool Find(int x)
{
    for (int i=1;i<=m;i++)
    {
        if (Map[x][i]==1&&!vis[i])
        {
            vis[i]=1;
            if (ok[i]==-1)
            {
                ok[i]=x;
                return true;
            }
            else
            {
                if (Find(ok[i])==true)
                {
                    ok[i]=x;
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    int k,i,x,y;
    int ans;
    while (~scanf("%d",&n))
    {
        ans=0;
        memset(Map,0,sizeof(Map));
        memset(ok,-1,sizeof(ok));
        if (n==0)
            break;
        scanf("%d%d",&m,&k);
        while (k--)
        {
            scanf("%d%d%d",&i,&x,&y);

                Map[x][y]=1;
        }
        for (int j=1;j<=n;j++)
        {
            memset(vis,0,sizeof(vis));
            if (Find(j)==true)
                ans++;
        }
        printf ("%d\n",ans);
    }
    return 0;
}
