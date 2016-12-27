#include <cstring>
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    int n,m,a,b,c,x[101][101],v[101][101];
    memset(x,0x3f,sizeof(x));
    memset(v,0,sizeof(v));
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; ++i){scanf("%d%d%d",&a,&b,&c);x[a][b]=min(c,x[a][b]);}
    for(int k=1; k<=n; ++k)
        for(int i=1; i<=n; ++i)
            for(int j=i+1; j<=n; ++j)
                {if(x[i][j]>x[i][k]+x[k][j])x[i][j]=x[i][k]+x[k][j];
                if(x[i][j]==x[i][k]+x[k][j])++v[i][j];
                }
    printf("%d %d\n",x[1][n],v[1][n]+1);
    return 0;
}
