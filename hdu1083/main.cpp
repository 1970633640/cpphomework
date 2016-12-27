#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int n,p,q;
bool x[1001][1001];  //course--student
bool vis[1001];
int link[1001];

bool find(int c)
{
    for(int i=1; i<=p; ++i)
    {
        if(!vis[i] && x[c][i])
        {
            vis[i]=1;
            if(link[i]==-1 || find(i))
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
    int nn,t;
    scanf("%d",&nn);
    for(int ii=0; ii<nn; ++ii)
    {
        scanf("%d%d",&n,&p);
        memset(x,0,sizeof(x));
        for(int i=1; i<=n; ++i)
        {
            scanf("%d",&q);
            for(int j=0; j<q; ++j)
            {
                scanf("%d",&t);
                x[i][t]=1;
            }
        }

        memset(link,-1,sizeof(link));
        int ans=0;
        for(int i=1; i<=n; ++i)
        {
            memset(vis,0,sizeof(vis));
            if(find(i))++ans;
        }
        if (ans == n) printf ("YES\n");
        else printf ("NO\n");
    }
    return 0;
}
