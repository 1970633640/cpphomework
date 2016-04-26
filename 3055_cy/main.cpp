#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

double fre[26];

bool cmp(const char a,const char b)
{
    int n,m;
    n=a>'Z'?a-'a':a-'A';
    m=b>'Z'?b-'a':b-'A';
    if(fre[n]!=fre[m]) return fre[n]>fre[m];
    else
    {
        if(n==m) return a>b;
        else return n<m;
    }
}

int main()
{
    int T,t;
    cin>>T;
    for(t=0; t<T; t++)
    {
        int i;
        for(i=0; i<26; i++)
            cin>>fre[i];
        string str;
        cin>>str;
        sort(str.begin(),str.end(),cmp);
        cout<<"case #"<<t<<":"<<endl<<str<<endl;
    }
    return 0;
}
