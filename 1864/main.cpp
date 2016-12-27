#include <iostream>
#include <cstring>
#include <string>
#include <stdio.h>
using namespace std;

char cube[51][52];
char query[52];
bool x[51][51];   //box整体 -- query的字符
bool used[51];//cube
int link[51];//cube
int n,q;//cube query
bool check(char a[],char b)
{
    for(int i=0; i<strlen(a); ++i)
        if(a[i]==b)return true;
    return false;
}

bool find(int c)   //char
{
    int i,j;
    for (j=1; j<=n; ++j)   //cube
    {
        if (x[j][c] && !used[j])
        {
            used[j]=1;
            if (link[j]==-1 || find(link[j]))
            {
                link[j]=c;
                return true;
            }
        }
    }
    return false;
}

int main()
{
   // std::ios::sync_with_stdio(false);
    while(scanf("%d",&n)!=EOF)
    {
        bool flag=false;
       scanf("%d",&q);
        for(int i=1; i<=n; ++i)scanf("%s",cube[i]);
        for(int i=1; i<=q; ++i)
        {
            int ans=0;
            scanf("%s",query);
            for(int j=0; j<strlen(query); ++j)
                for(int k=1; k<=n; ++k)
                    x[k][j]=check(cube[k],query[j]);
            for(int j=0; j<=50; ++j)link[j]=-1;
            for(int j=0; j<strlen(query); ++j )
            {
                memset(used,0,sizeof(used));
                if(find(j))++ans;
            }
            if(ans==strlen(query))
            {
                if(!flag)
                {
                    printf("%d",i-1);
                    flag=true;
                }
                else  cout<<" "<<i-1;
            }
        }
        if(flag)printf("\n");
        else printf("-1\n");
    }
    return 0;
}
