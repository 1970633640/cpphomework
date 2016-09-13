#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define MAXN 100001
int q[MAXN];
int head=0,tail=0;
int en(int x)
{
    tail=(tail+1)%MAXN;
    if(tail==head)
    {
        if(tail==0)tail=MAXN-1;
        else tail--;
        return 1;
    }
    q[tail]=x;
    return 0;
}

int de(int *p)
{int ans=q[head+1];
    if(head==tail)return -1;
    head=(head+1)%MAXN;
*p =q[head];
return ans;
}

int main()
{

int i,x;
scanf("%d\n",&x);
char a[8];int b;
for(i=0;i<x;i++)
{
    {
        scanf("%s",a);
        if(a[0]=='e'){scanf("%d\n",&b);en(b);}
        else {
            printf("%d\n",de(q));
        }
    }
}
}
