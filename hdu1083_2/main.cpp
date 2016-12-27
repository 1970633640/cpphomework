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

using namespace std;

typedef long long int LL;
const double pi = (acos(-1));
const int maxn = 1000;
int g[maxn][maxn], used[maxn], link[maxn];
int nx, ny;

bool dfs (int u) {
    for (int v = 1; v <= ny; v++) {
        if (g[u][v] && !used[v]) {
            used[v] = 1;
            if (link[v] == -1 || dfs (link[v])) {
                link[v] = u;
                return true;
            }
        }
    }
    return false;
}

int maxmatch () {
    int res = 0;
    memset (link, -1, sizeof (link));
    for (int i = 1; i <= nx; i++) {
        memset (used, 0, sizeof (used));
        if (dfs (i)) res++;
    }
    return res;
}

int main()
{
    //freopen("D:\\Test_in.txt", "r", stdin);
    //freopen("D:\\Test_out.txt", "w", stdout);
    int T;
    scanf ("%d", &T);
    while (T--) {
        scanf ("%d%d", &nx, &ny);
        memset (g, 0, sizeof (g));
        for (int i = 1; i <= nx; i++) {
            int n;
            scanf ("%d", &n);
            for (int j = 0; j < n; j++) {
                int a;
                scanf ("%d", &a);
                g[i][a] = 1;
            }
        }

        int ans = maxmatch ();
        if (ans == nx) printf ("YES\n");
        else printf ("NO\n");
    }
    return 0;
}
