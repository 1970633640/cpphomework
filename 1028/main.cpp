#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <stdio.h>
using namespace std;

map <string,int>data;
int dis[101][101];//option base 1

int main()
{
    std::ios::sync_with_stdio(false);
    memset(dis,0x3f,sizeof(dis));
    int n,road,query;
    string ip1,ip2;
    int ping;
    cin>>n>>road;
    int sum=0;
    for(int i=1; i<=road; ++i)
    {
        cin>>ip1>>ip2>>ping;
        if(data.find(ip1)==data.end())
        {
            ++sum;
            data[ip1]=sum;
        }
        if(data.find(ip2)==data.end())
        {
            ++sum;
            data[ip2]=sum;
        }
        dis[data[ip2]][data[ip1]]=dis[data[ip1]][data[ip2]]=ping;
    }
    for(int k=1; k<=n; ++k)
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=n; ++j)
                if(dis[i][j]>dis[i][k]+dis[k][j])
                    dis[i][j]=dis[i][k]+dis[k][j];
    cin>>query;
    for(int i=1; i<=query; ++i)
    {

        cin>>ip1>>ip2;
        if(dis[data[ip1]][data[ip2]]<111111)cout<<dis[data[ip1]][data[ip2]]<<endl;
        else cout<<"-1\n";
    }
    return 0;
}
