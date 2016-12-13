#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
using namespace std;
typedef struct node
{
    int x;
    int y;
    int value;
} node;
typedef struct pos
{
    int x;
    int y;
    pos(int a,int b){x=a;y=b;}
}pos;
int N,M;
int fx[8]= {0,1,1,1,0,-1,-1,-1}; //从↑开始顺时针一圈
int fy[8]= {1,1,0,-1,-1,-1,0,1};
int x[701][701];  //数据全部从1开始
bool vis[701][701]= {0};
node x2[491401];
stack <pos> STACK;
int cmp(const void * a,const void * b)
{
    return (*(node *)b).value-(*(node *)a).value;
}
void dfs(int X,int Y)
{
    for(int i=0; i<8; ++i)
    {
        int XX=X+fx[i];
        int YY=Y+fy[i];
        if(XX>=1 && XX<=M && YY>=1 && YY<=N && !vis[YY][XX] && x[YY][XX]<=x[Y][X]){vis[YY][XX]=true;STACK.push(pos(XX,YY));}
    }
}


int main()
{
    scanf("%d%d",&N,&M);
    int sum=0,ans=0;
    for(int i=1; i<=N; ++i)
        for(int j=1; j<=M; ++j)
        {
            scanf("%d",&x[i][j]);
            x2[++sum].value=x[i][j];
            x2[sum].x=j;
            x2[sum].y=i;
        }
    qsort(x2+1,N*M,sizeof(x2[1]),cmp);
    for(int i=1; i<=N; ++i)
        for(int j=1; j<=M; ++j)
            if(  !  vis[x2[(i-1)*M+j].y][x2[(i-1)*M+j].x]  )
            {
                ++ans;
                STACK.push(pos(x2[(i-1)*M+j].x,x2[(i-1)*M+j].y));
                while(!STACK.empty()){pos p=STACK.top();STACK.pop();
                vis[p.y][p.x]=true;
                dfs(p.x,p.y);}
            }
    printf("%d\n",ans);
    return 0;
}
