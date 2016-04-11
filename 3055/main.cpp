#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <float> f;

bool cmp(char a,char b)
{
    if(a-b==32 || b-a==32)return a>b;
    if ((a-'A')>26)a-=32;
    if ((b-'A')>26)b-=32;
    return f[a-'A']>f[b-'A'];
}

int main()
{
    int n,i,k;
    double temp;
    string x;
    cin>>n;
    for(i=0; i<n; i++)
    {
        f.clear();
        for(k=0; k<26; k++)
        {
            cin>>temp;
            f.push_back(temp);
        }
        cin>>x;
        sort(x.begin(),x.end(),cmp);
        cout<<"case #"<<i<<":"<<endl;
        cout<<x<<endl;
    }
    return 0;
}
