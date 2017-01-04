#include <iostream>
#include <stdio.h>
using namespace std;
const int modulo= 98765431;
int c[50001];
long long reduce(long long x, long long n, int modulo)
{
    long long ans;
    if(n == 0)
        return 1;
    if(n == 1)
        return x % modulo;
    ans=reduce(x, n>>1,modulo);
    ans=ans * ans % modulo;
    if(n & 1)
        ans=ans * x % modulo;
    return ans;
}
long long f(int n, int t)
{
    long long ans;
    long long a=reduce(n-1, t,modulo);
    long long b=reduce(n, modulo - 2,modulo);
    if(t & 1)
        ans=((1+a) * b) % modulo;
    else
        ans=((-1+a) * b) % modulo;
    return ans;
}
int main()
{
    int n, t;
    scanf("%d%d", &n, &t);
    long long sum=0;
    for(int i=1; i <= n; i++)
    {
        scanf("%d", &c[i]);
        sum=(sum+c[i]) % modulo;
    }
    long long ans=f(n, t) * sum % modulo;
    if(t%2!=0)
        for(int i=1; i <= n; i++)
            printf("%I64d\n", (ans+modulo - c[i]) % modulo);
    else
        for(int i=1; i <= n; i++)
            printf("%I64d\n", (ans+c[i]) % modulo) ;
    return 0;
}
