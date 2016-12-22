#include <iostream>
#include <cmath>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
//kruskal
using namespace std;
typedef struct edge
{
    int point1;
    int point2; //1<=2
    double dis;
} edge;
typedef struct pos
{
    int x;
    int y;
} pos;
int root[1001];
int cmp(const void *a,const void *b)
{
    return (*(edge*)a).dis>(*(edge*)b).dis?1:-1;
}
pos p[1001];
edge e[1001];

int find(int x)
{
    if(root[x]==x)return x;
    else return find(root[x]);  //并查集加速
}

int main()
{
    int N,M;
    int a,b;
    double ans;
    scanf("%d%d",&N,&M);
    for(int i=1; i<=N; ++i)root[i]=i;
    for(int i=1; i<=N; ++i)
        scanf("%d%d",&p[i].x,&p[i].y);
    int sume=-1;
    for(int i=1; i<=N; ++i)
        for(int j=i; j<=N; ++j)
        {
            e[++sume].point1=i;
            e[sume].point2=j;
            e[sume].dis=sqrt((double)((double)(p[i].x-p[j].x)*(double)(p[i].x-p[j].x)+(double)(p[i].y-p[j].y)*(double)(p[i].y-p[j].y)));
        }

    for(int i=1; i<=M; ++i)
    {
        scanf("%d%d",&a,&b);
       // if(find(a)!=find(b))
       //     root[b]=a;
       e[++sume].point1=a;
       e[sume].point2=b;
       e[sume].dis=0;
    }
    qsort(e,sume+1,sizeof(e[0]),cmp);
        for(int i=0; i<=sume; ++i)printf("%d %d %f\n",e[i].point1,e[i].point2,e[i].dis);
    for(int i=0; i<=sume; ++i)
    {
        if(  find(e[i].point1) !=find(e[i].point2)  )
        {
           // for(int j=0;j<=sume;++j)cout<<"--"<<find(e[i].point1)<<find(e[i].point2)<<endl;
            root[e[i].point2]=e[i].point1;
            ans+=e[i].dis;

        }
    }
    printf("%f\n",ans);
    return 0;
}
