#include <iostream>

using namespace std;
int x[101][101];
int sum[101][101];
int f(int n)
{
    int i,j;
    for(i=n;i>=1;i--)sum[n][i]=x[n][i];
    for(i=n-1;i>=1;i--)
        for(j=i;j>=1;j--)
             sum[i][j]=x[i][j]+min(sum[i+1][j],sum[i+1][j+1]);
return sum[1][1];
}
int main()
{
    int i,j,n,nn,ii;
    cin>>nn;
    for(ii=0; ii<nn; ii++)
    {
        cin>>n;
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=i; j++)cin>>x[i][j];
        }

cout<<f(n)<<endl;
    }
    return 0;
}
