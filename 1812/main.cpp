#include <iostream>

using namespace std;
int x[10001];  //按照题意有几个节点就用几个数字，无需散列
int f(int a)
{
    int ans=0;
    while(x[a]!=a){a=x[a];++ans;}  //查找父节点
    return ans;
}
int main()
{
    int n;cin>>n;int a,b,m=0,i;
    for(i=1;i<=n;i++)x[i]=i; //初始化父节点就是自己
    for(i=1;i<=n;i++)
    {
        cin>>a>>b;
        if(a!=0)x[a]=i; //记录每个节点的父节点是谁
        if(b!=0)x[b]=i;
    }
    for(i=1;i<=n;i++){int t=f(i);if(t>m)m=t;} //依次比较求最长路径，时间足够不考虑优化
    cout<<m+1<<endl;
    return 0;
}
