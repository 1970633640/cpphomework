#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
using namespace std;
int root[100];
bool used[100];
int flag;
int gotohead(int a)
{
    while(a!=root[a])a=root[a];
    return a;
}
int connect(int a,int b)
{
    a=gotohead(a);
    b=gotohead(b);
    if(a!=b)root[b]=a;
}
void check(int x)
{
    for(int i=1; i<100; i++)if(used[i]==1 &&gotohead(i)!=gotohead(x))
        {
            flag=0;
            break;
        }
}
int main()
{
    int a,b,i;
    int start,first;
    int n=0;
init:
    for(i=0; i<100; i++)
    {
        root[i]=i;
        used[i]=false;
    }
    n++;
    flag=1;
    start=0;
    while(1)
    {
        scanf("%d %d",&a,&b);
        if(a==-1)return 0;
        if(a==0 && start==0)
        {
            printf("Case %d is a tree.\n",n);
            goto init;
        }
        if(a!=0 && start==0)
        {
            first=a;
            start=1;
        }
        used[a]=true;
        used[b]=true;
        if(a!=0 && a==b)flag=0;
        if(a!=0)
        {
            if(flag==1 && gotohead(a)==gotohead(b))flag=0;
            if(flag==1)connect(a,b);
        }
        else
        {
            if(flag==1)check(first);
            if(flag==1)
            {
                printf("Case %d is a tree.\n",n);
                goto init;
            }
            else
            {
                printf("Case %d is not a tree.\n",n);
                goto init;
            }
        }
    }
    return 0;
}
