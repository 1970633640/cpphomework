#include <iostream>
#include <map>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
using namespace std;
typedef struct node
{
    int root;
    int eat;   //0同类 1root吃他 2他吃root
} node;
node x[50000];
int same(int a,int b)
{
    int ans1=0,ans2=0;
    while(x[a].root!=a)
    {
        ans1+=x[a].eat;
        a=x[a].root;
    }
    while(x[b].root!=b)
    {
        ans2+=x[b].eat;
        b=x[b].root;
    }
  //  if(a==b)printf("ans1=%d ans2=%d \n",ans1,ans2);
    if(a==b)return (ans1-ans2+333333)%3;
    else return -1;
}
int gototop(int a)
{
    int ans=0;
    while(x[a].root!=a)
    {
        ans+=x[a].eat;
        a=x[a].root;
    }
    return ans%3;
}

int whereistop(int a)
{
    while(x[a].root!=a)a=x[a].root;
    return a;
}

int main()
{
    int m,n,i,d,a,b;    //m=max   a吃b
    int e=0;
    scanf("%d%d",&m,&n);
    for(i=0; i<=m; i++)
    {
        x[i].root=i;
        x[i].eat=0;
    }

    for(i=0; i<n; i++)
    {

        scanf("%d%d%d",&d,&a,&b);
        if(a>m||b>m)
        {
            e++;
            continue;
        }
        else if(d==2 && a==b)
        {
            e++;
            continue;
        }
        if(d==1)
        {
            int temp=same(a,b);
            if(temp==1||temp==2)
            {
                e++;
                continue;
            }
            if(temp==0)continue;
            if(temp==-1)
            {
                int c=whereistop(b);
                int sum=gototop(b);
                x[c].root=a;
                x[c].eat=(3-sum+333333)%3;
                continue;
            }
        }
        else if(d==2)
        {
            int temp=same(a,b);
            if(temp==2)continue;
            if(temp==1||temp==0)
            {
                e++;
                continue;
            }
            if(temp==-1)
            {
                int c=whereistop(b);
                int sum=gototop(b);
                x[c].root=a;
                x[c].eat=(3-sum+333334)%3;
                continue;
            }
        }

    }
    printf("%d\n",e);
    return 0;
}
