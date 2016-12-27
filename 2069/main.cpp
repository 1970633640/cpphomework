#include <cstring>
#include <cstdio>


using namespace std;
bool x[501][501];  //行列
bool vis[501];
int link[501];//答案
int n;

bool find2(int c)   //char
{
    for (int j=1; j<=n; ++j)   //cube
    {
        if ( !vis[j] && x[c][j])
        {
            vis[j]=1;
            if (link[j]==-1 || find2(link[j]))
            {
                link[j]=c;
                return true;
            }
        }
    }
    return false;
}

int main()
{

    int k,a,b;
    scanf("%d%d",&n,&k);
    memset(x,0,sizeof(x));
    for(int i=0; i<k; ++i)
    {
        scanf("%d%d",&a,&b);
        x[a][b]=true;
    }
    int ans=0;
    memset(link,-1,sizeof(link));

    for(int i=1; i<=n; ++i)
    {
        memset(vis,0,sizeof(vis));
        if(find2(i)) ++ans;
    }


    printf("%d\n",ans);

    return 0;
}
