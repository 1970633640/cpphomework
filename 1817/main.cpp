#include <cstring>
#include <stdio.h>
using namespace std;

int main()
{
    int n,m,a,b,c,x[600][600];
    memset(x,0x3f,sizeof(x));
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; ++i){scanf("%d%d%d",&a,&b,&c);x[a][b]=c;}
    for(int k=1; k<=n; ++k)
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=n; ++j)
                if(x[i][j]>x[i][k]+x[k][j])x[i][j]=x[i][k]+x[k][j];
    printf("%d\n",x[1][n]<1061109567?x[1][n]:-1);
    return 0;
}
