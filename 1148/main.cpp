#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
using namespace std;
int n;
bool success=false;
int ans[11][11]={0};  //还是从1开始计数好理解
int suc[101]= {0};
bool sushu[200]={0};
int sushus[46]= {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199};  //2~200的素数
bool find2 (int x)
{
  return sushu[x];
}

bool judge(int x,int y)
{
    if(y>=2 && !find2(ans[y][x]+ans[y-1][x]))return false;
    if(x>=2 && !find2(ans[y][x]+ans[y][x-1]))return false;
    return true;
}

void print()
{
        for(int i=1;i<=n;++i)
{for(int j=1;j<n;++j)printf("%d ",ans[i][j]);printf("%d\\n",ans[i][n]);}

}

void dfs (int x,int n)
{
if(success)return;
    if(x>n*n){success=1;return;}
    int Y=(x-1)/n+1;
    int X=(x-1)%n+1;
    for(int i=1; i<=n*n && !success; ++i)
    {
        if(!suc[i])
        {suc[i]=1;
            ans[Y][X]=i;
            if(judge(X,Y))
                dfs(x+1,n);
               else ans[Y][X]=0;
        }
        else continue;
        suc[i]=0;
    }
return;
}
int main()
{
    for(int i=0; i<46; ++i)sushu[sushus[i]]=true;
   for(int i=1;i<=10;++i){
        n=i;
        success=false;
   memset(suc,0,sizeof(suc));
   printf("x[%d]=\"",n);
    dfs(1,n);
if(success)print();else printf("no answer\\n");
printf("\";\n");
   }
    return 0;
}
