#include <iostream>
#include <cstring>

using namespace std;



int main()
{
   int n;
   int w[20];
   while(cin>>n)
    {
int c[20][1000]={0};
       int i,sum=0,j;
       for(i=0;i<n;++i)
       {
           cin>>w[i];
           sum+=w[i];
       }

for(j=0;j<=sum/2;j++)
        for(i=0;i<=n;i++)
    {
        if(j<w[i])
        {
            c[i][j]=c[i-1][j];
            continue;
        }else if(c[i-1][j-w[i]]+1>c[i-1][j])
            c[i][j]=c[i-1][j-w[i]]+1;
        else
            c[i][j]=c[i-1][j];
    }

cout<<"--"<<sum-2*c[n][sum/2]<<"--"<<endl;
    }
   return 0;
}
