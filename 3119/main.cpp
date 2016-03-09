#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> a;
    int i,t;
    for(i=0; i<3; i++)
    {
        cin>>t;
        a.push_back(t);
    }
    sort(a.begin(),a.end());
    for(i=0; i<2; i++)
    {
        cout<<a[i]<<' ';
    }
    cout<<a[i]<<endl;
    return 0;
}
