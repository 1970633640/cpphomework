#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <queue>
#include <new>
#include <set>
#include <map>
#include <windows.h>

using namespace std;

typedef long long int LL;
const double pi = (acos(-1));
const int maxn = 1000;
int link[maxn], g[maxn][maxn];
bool used[maxn];
int nx, ny, n, m;

bool dfs (int u)
{
    for (int v = 1; v <= ny; v++)
    {
        if (!used[v] && g[u][v])
        {
            used[v] = true;
            if (link[v] == -1 || dfs (link[v]))
            {
                link[v] = u;
                return true;
            }
        }
    }
    return false;
}

int maxmatch ()
{
    int res = 0;
    memset (link, -1, sizeof (link));//link[i]=-1表示i不在匹配中，否则(link[i],i)这条边在匹配中
    for (int i = 1; i <= nx; i++)
    {
        memset (used, false, sizeof (used));
        if (dfs (i)) res++;
    }
    return res;
}

int main()
{
    freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    scanf ("%d%d", &n, &m);
        nx = ny = n;
        memset (g, 0, sizeof (g));
        for (int i = 0; i < m; i++)
        {
            int a, b;
            scanf ("%d%d", &a, &b);
            g[a][b] = 1;
        }

        printf ("%d\n", maxmatch ());


    return 0;
}
