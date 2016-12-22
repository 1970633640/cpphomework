#include <iostream>
#include <cmath>
#include <cstring>
#include <stdio.h>
//prim
using namespace std;
typedef struct pos
{
    int x;
    int y;
} pos;

pos p[1001];
bool vis[1001];
double dis[1001][1001];
void cal(int a,int b)
{
    if(a<=b)
        dis[a][b]=sqrt((double)((double)(p[a].x-p[b].x)*(double)(p[a].x-p[b].x)+(double)(p[a].y-p[b].y)*(double)(p[a].y-p[b].y)));
    else
        dis[a][b]=dis[b][a];
}

int main()
{
    int N,M;
    int a,b;
    scanf("%d%d",&N,&M);
    for(int i=1; i<=N; ++i)
        scanf("%d%d",&p[i].x,&p[i].y);
    for(int i=1; i<=N; ++i)
        for(int j=1; j<=N; ++j)
            cal(i,j);
    for(int i=1; i<=M; ++i)
    {
        scanf("%d%d",&a,&b);
        dis[a][b]=0;
        dis[b][a]=0;
    }
    memset(vis,0,sizeof(vis));
    vis[1]=true;
    double ans=0.0;
    int sum=1;
    double mindis;
    int minv;
//int nearvex[1001];用不着
double lowcost[1001];
int near[1001];
for(int i=1;i<=N;++i){lowcost[i]=99999999999.9;near[i]=-1;}
int i=1;
    while(1)
    {
        for(int j=1;j<=N;++j)if(!vis[j] && dis[i][j]<lowcost[j]){lowcost[j]=dis[i][j];near[j]=i;}
        mindis=99999999999.9;
                for(int j=1; j<=N; ++j)
                    if(!vis[j] && lowcost[j]<mindis)
                    {
                        mindis= lowcost[j];
                        minv=j;
                    }
                    if(mindis>9999999999.9)break;
            ans+=mindis;
            vis[minv]=1;

       //    cout<<near[minv]<<minv<<" "<<mindis<<endl;
            i=minv;
    }

printf("%.2f\n",ans);
return 0;
}
