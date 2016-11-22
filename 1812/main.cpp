#include <iostream>

using namespace std;
int x[10001];
int f(int a)
{
    int ans=0;
    while(x[a]!=a){a=x[a];++ans;}
    return ans;
}
int main()
{
    int n;cin>>n;int a,b,m=0,i;
    for(i=1;i<=n;i++)x[i]=i;
    for(i=1;i<=n;i++)
    {
        cin>>a>>b;
        if(a!=0)x[a]=i;
        if(b!=0)x[b]=i;
    }
    for(i=1;i<=n;i++){int t=f(i);if(t>m)m=t;}
    cout<<m+1<<endl;
    return 0;
}
