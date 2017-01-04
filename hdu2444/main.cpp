#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
bool x[201][201];
int n;
int link[201];
bool used[201];

bool check()
{
    int color[201];
    color[1]=0;
    memset(color,-1,sizeof(color));
    queue <int> q;
    q.push(1);
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        for(int i=1; i<=n; ++i)
        {
            if(x[t][i] && color[i]==-1)
            {
                color[i]=1-color[t];
                q.push(i);
            }
            else if(x[t][i] && color[i]==color[t])
                return false;
        }
    }
    return true;
}

bool f(int c)
{
    for(int i=1; i<=n; ++i)
    {
        if(x[c][i] && !used[i])
        {
            used[i]=1;
            if(link[i]==-1 || f(link[i]))
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
    int m,a,b;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(x,0,sizeof(x));
        while(m--)
        {
            scanf("%d%d",&a,&b);
            x[a][b]=x[b][a]=1;
        }
        if(check())
        {
            memset(link,-1,sizeof(link));
            int ans=0;
            for(int i=1; i<=n; ++i)
            {
                memset(used,0,sizeof(used));
                if(f(i))++ans;
            }
            printf("%d\n",ans/2);
        }
        else printf("No\n");
    }
    return 0;
}
