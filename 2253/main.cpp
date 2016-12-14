#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
bool vis[9][9];
bool success;
int ans[27][2],p,q;   //ans[][0]=x,[1]=y
int fx[8]= {-1,1,-2,2,-2,2,-1,1};
int fy[8]= {-2,-2,-1,-1,1,1,2,2};

void dfs(int x,int y,int step)
{
    if(step==p*q ||success){success=true;return;}
    else
    {
        for(int i=0; i<8; ++i)
        {
            int xx=x+fx[i];
            int yy=y+fy[i];
            if(xx>=1 && xx<=p && yy>=1 && yy<=q && !vis[yy][xx] &&!success)
            {
                ans[step][0]=xx;
                ans[step][1]=yy;
                vis[yy][xx]=true;
                dfs(xx,yy,step+1);
                vis[yy][xx]=false;
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int ii=0; ii<n; ++ii)
    {
        scanf("%d%d",&p,&q);  //p是列数,q是行数
        memset(vis,0,sizeof(vis));
        memset(ans,0,sizeof(ans));
        success=false;
        vis[1][1]=true;
        ans[0][0]=ans[0][1]=1;
        dfs(1,1,1);
        printf("Scenario #%d:\n",ii+1);
        if(success)
for(int i=0;i<p*q;++i)printf("%c%d",'A'-1+ans[i][1],ans[i][0]);
            else
            printf("impossible");
            printf("\n");
    }
    return 0;
}
