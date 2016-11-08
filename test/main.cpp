#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int x[1000]= {0};
    int m=0,p=0;
    while(1)
    {

        if(x[p]==0)
        {
            m=(m+1)%3;
            if(m==0)x[p]=1;
        }
        int sum=0,ans;
        for(int i=0; i<n; i++)if(x[i]==0)
            {
                ans=i;
                sum++;
            }
        if(sum==1)
        {
            cout<<ans+1;
            break;
        }
        p=(p+1)%n;
    }
    return 0;
}
