#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int x[201][201];
int sum[201][201];
int p[201],q[201];
int n;
int main()  //需要优化
{
    int n;
    while(scanf("%d",&n)==1&&n)
    {
        for(int i=1; i<=n; ++i)
            scanf("%d",&p[i]);
        for(int i=0; i<=n; ++i)
            scanf("%d",&q[i]);
        for(int i=1; i<=n; ++i)
            sum[i][i]=p[i]+q[i]+q[i-1];
        for(int d=1; d<n; ++d)
            for(int i=1; i+d<=n; ++i)
                sum[i][i+d]=sum[i][i+d-1]+p[i+d]+q[i+d];
        for(int i=1; i<=n+1; ++i)
        {
            x[i][i-1]=0;
            sum[i][i-1]=q[i-1];
        }
        for(int d=0; d<n; ++d)
            for(int i=1; i+d<=n; ++i)
            {
                int j=i+d;
                int minx=0x3f3f3f3f;
                for(int k=i; k<=j; ++k)
                    minx=min(minx,x[i][k-1]+x[k+1][j]);
                x[i][j]=minx+sum[i][j];
            }
        printf("%d\n",x[1][n]);
    }
    return 0;
}
