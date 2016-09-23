#include <iostream>

using namespace std;

int main()
{
    int n,i,j,x[1025];
    cin>>n;
    for(i=0; i<n; i++)cin>>x[i];
    for(i=0; i<n-1; i++)
        for(j=n-2; j>=0; j--)
            if(x[j]>x[j+1])swap(x[j],x[j+1]);
    for(i=0; i<n-1; i++)cout<<x[i]<<" ";
    cout<<x[i]<<endl;
    return 0;
}
