#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
int n,m;
char x[201][201];
bool flag;
typedef struct pos
{
    int x;
    int y;
    pos(int a,int b){x=a;y=b;}
    pos(){x=0;y=0;}
} pos;
queue <pos> q;
queue <pos> temp;
int sum;
int f()
{
    pos p;
    pos p2;
    while(!q.empty()){   ++sum;if(sum>10000)return 0;int s=q.size();
   for(int i=0;i<s;++i)
   {
       p=q.front();
      q.pop();
       flag=false;

              if(p.x+1<=m && x[p.y][p.x+1]=='.'){x[p.y][p.x+1]='#';q.push(pos(p.x+1,p.y));}
            if(p.x-1>=1 && x[p.y][p.x-1]=='.'){x[p.y][p.x-1]='#';q.push(pos(p.x-1,p.y));}
             if(p.y+1<=n && x[p.y+1][p.x]=='.'){x[p.y+1][p.x]='#';q.push(pos(p.x,p.y+1));}
             if(p.y-1>=1 && x[p.y-1][p.x]=='.'){x[p.y-1][p.x]='#';q.push(pos(p.x,p.y-1));}

     if(p.x+1<=m && x[p.y][p.x+1]=='X'){temp.push(pos(p.x+1,p.y));flag=true;}
     if(p.x-1>=1 && x[p.y][p.x-1]=='X'){temp.push(pos(p.x-1,p.y));flag=true;}
     if(p.y+1<=n && x[p.y+1][p.x]=='X'){temp.push(pos(p.x,p.y+1));flag=true;}
     if(p.y-1>=1 && x[p.y-1][p.x]=='X'){temp.push(pos(p.x,p.y-1));flag=true;}

        if(p.x+1<=m && x[p.y][p.x+1]=='T')return 1;
        if(p.x-1>=1 && x[p.y][p.x-1]=='T')return 1;
        if(p.y+1<=n && x[p.y+1][p.x]=='T')return 1;
       if(p.y-1>=1 && x[p.y-1][p.x]=='T')return 1;
if(flag)q.push(pos(p.x,p.y));
   }

  while(!temp.empty()){
        p2=temp.front();
        temp.pop();x[p2.y][p2.x]='.';
  }

}
return 0;
}


int main()
{
    while(scanf("%d%d\n",&n,&m)!=EOF)
    {
        for(int i=1; i<=n; ++i)
        {
            for(int j=1; j<=m; ++j)
                x[i][j]=getchar();
            getchar();
        }
        while(!q.empty())q.pop();
        sum=0;
        pos p;
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=m; ++j)if(x[i][j]=='S')
                {
                    p.y=i;
                    p.x=j;
                    break;
                }
        q.push(p);x[p.y][p.x]='#';

if(f())
        printf("%d\n",sum);
else
        printf("impossible\n");
    }
    return 0;
}
