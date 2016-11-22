#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n,x,sum=0;
    vector <int> v;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&x);
        v.push_back(x);
    }
    while(v.size()!=1)
    {
        sort(v.begin(),v.end());
        x=*v.begin()+*(v.begin()+1);
        v.erase(v.begin());
        v.erase(v.begin());
        sum+=x;
        v.push_back(x);
    }
    printf("%d",sum);
    return 0;
}
