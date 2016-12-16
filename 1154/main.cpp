#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

long long int ans[100000];
long long int ans2[100000];
long long int m;

long long int gcd(long long int x, long long int y)
{
    return (y == 0) ? x : gcd(y, x % y);
}
bool better()
{//prlong long intf("compare %d %d\n",ans[m],ans2[m]);
    if(ans2[m]==0 || ans[m]<ans2[m])return true;
    else return false;
}
bool dfs(long long int a,long long int b,long long int step,long long int last)
{
    long long int c=gcd(a,b);
    a=a/c;
    b=b/c;
    if(step==m)
    {
        if(a!=1)
            return false;
        else
        {ans[m]=b;
            if(better())memcpy(ans2,ans,sizeof(ans));
            return true;
        }
    }
    bool success=false;
    for(long long int i=max(last , b%a==0?b/a:b/a+1 );; ++i)
    {
        if(a*i>=b*(m-step+1))   //   a/b>=(m-step+1)/i
            break;

        ans[step]=i;
        long long int aa=a*i-b;
        long long int bb=b*i;       //   a/b-1/i= (ai-b) / (b*i)
    //    prlong long intf("%d \/ %d  -1\/%d = %d\/%d\n",a,b,i,aa,bb);
        if( dfs(aa,bb,step+1,i+1) )success=true;
    }
    return success;
}

int main()
{
    long long int a,b;
    while(scanf("%I64d%I64d",&a,&b)!=EOF)
    {
        memset(ans2,0,sizeof(ans2));
        for(m=1; m<100000; ++m)
        {
            if(dfs(a,b,1,b%a==0?b/a:b/a+1))break;
        }
       printf("%I64d",ans2[1]);
        for(long long int i=2; i<=m; ++i)
            printf(" %I64d",ans2[i]);
            printf("\n");
    }
    return 0;
}
