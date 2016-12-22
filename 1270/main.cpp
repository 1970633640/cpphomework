#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <stdio.h>

using namespace std;
map <string,int> data;
double dis[101][101];//option base 1
void init(int n)
{
    memset(dis,0,sizeof(dis));
    for(int i=1; i<=n; ++i)dis[i][i]=1.0000000;
}
int main()
{
    std::ios::sync_with_stdio(false);
    int n,q,sum=0;
    while(1)
    {
        cin>>n;
        if(n==0)break;
        init(n);
        data.clear();
        string name,c1,c2;
        double rate;
        for(int i=1; i<=n; ++i)
        {
            cin>>name;
            data[name]=i;
        }
        cin>>q;
        for(int i=1; i<=q; ++i)
        {
            cin>>c1>>rate>>c2;
            dis[data[c1]][data[c2]]=rate;
            //  dis[data[c2]][data[c1]]=1.0/rate;
        }
        for(int k=1; k<=n; ++k)
            for(int i=1; i<=n; ++i)
                for(int j=1; j<=n; ++j)
                    if(dis[i][k]*dis[k][j]>dis[i][j])dis[i][j]=dis[i][k]*dis[k][j];
        for(int i=1; i<=n; ++i)
            if(dis[i][i]>1.0)
            {
                cout<<"Case "<<++sum<<": Yes\n";
                goto aaa;
            }
        cout<<"Case "<<++sum<<": No\n";
aaa:
        ;
    }
}
