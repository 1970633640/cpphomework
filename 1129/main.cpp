#include <iostream>

using namespace std;

int main()
{
    long long int jc[21];
    long long int f[21];
    int i,x,a,b;
    jc[0]=1;
    jc[1]=1;
    jc[2]=2;
    f[0]=1;
    f[1]=0;
    f[2]=1;
    for(i=3; i<=20; i++)
    {
        jc[i]=jc[i-1]*i;
        f[i]=(i-1)*(f[i-1]+f[i-2]);
    }
    cin>>x;
    for(i=0; i<x; i++)
    {
        cin>>a;
        cin>>b;
        cout<<jc[a]/jc[b]/jc[a-b]*f[b]<<endl;

    }
    return 0;
}
