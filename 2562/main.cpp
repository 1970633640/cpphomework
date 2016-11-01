#include <iostream>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
using namespace std;
int root[100005];
int num[100005];
map <string,int> x;

int trueroot(int a)
{
    int ans=a;
    while(ans!=root[ans]){ ans=root[ans];}
    while(a!=ans){int temp=root[a];root[a]=ans;a=temp;}
    return ans;
}

void f(int a,int b)
{
a=trueroot(a);
b=trueroot(b);
if(a!=b){num[a]+=num[b];root[b]=root[a];printf("%d\n",num[a]);}
else printf("%d\n",num[a]);
}

int main()
{
  //  ios::sync_with_stdio(false);
    int ii,nn,i,n;
  //  string a,b;
  char a[21],b[21];
    scanf("%d\n",&nn);
    for(ii=0; ii<nn; ii++)
    {
        x.clear();
        for(i=0; i<100005; i++){root[i]=i;num[i]=1;}

        scanf("%d",&n);int m=1;
        for(i=0; i<n; i++)
        {
           // cin>>a>>b;
           scanf("%s%s",a,b);
            if(x.find(a)==x.end())
            {
                x[a]=m;
                m++;
            }
            if(x.find(b)==x.end())
            {
                x[b]=m;
                m++;
            }
            f(x[a],x[b]);
        }
    }
    return 0;
}
