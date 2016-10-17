#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
int v[31];
int f(int num,int vmax)
{
    if(num==0 || vmax==0)return 0;
    else if (v[num]>vmax) return f(num-1,vmax) ;
    else return max(  f(num-1,vmax),f(num-1,vmax-v[num])+v[num]    );
}
int main()
{
    int vmax;
    int n,i;
    while(cin>>vmax)
    {
        cin>>n;
        memset(v,0,31);
        for(i=1; i<=n; i++)scanf("%d",&v[i]);
        cout<<vmax-f(n,vmax)<<endl;
    }
    return 0;
}
