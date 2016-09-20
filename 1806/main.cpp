#include <iostream>

using namespace std;

int main()
{
    int n,i,j,x[1025];
    cin>>n;
    for(i=0; i<n; i++)cin>>x[i];
    for(i=0; i<n-1; i++)
    {
        int temp=x[i],m=i;
        for(j=i; j<n; j++)if(x[j]<temp)
            {
                temp=x[j];
                m=j;
            }
        swap(x[i],x[m]);
    }
    for(i=0; i<n-1; i++)cout<<x[i]<<" ";
    cout<<x[i]<<endl;
    return 0;
}
