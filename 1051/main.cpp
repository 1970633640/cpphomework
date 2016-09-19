#include <iostream>
//long long int zui da 9223372036854775807
using namespace std;

int n;

long long int f(int *p)
{
    long long int m[51][51]= {0};
    long long int s[51][51]= {0};
    int i,j,L,k;
    for(i=1; i<=n; i++)
        m[i][i]=0;
    for(L=2; L<=n; L++)
    {
        for(i=1; i<=n-L+1; i++)
        {
            j=i+L-1;
            m[i][j]=9223372036854775807;
            for(k=i; k<=j-1; k++)
            {
                long long int q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<m[i][j])
                {
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
        }
    }

    return m[1][n];
}


int main()
{
    int ii,i,nn;
    cin>>nn;
    for(ii=0; ii<nn; ii++)
    {
        int p[52];
        cin>>n;
        for(i=1; i<=n; i++)
            cin>>p[i-1]>>p[i];
        cout<<f(p)<<endl;
    }
    return 0;
}
