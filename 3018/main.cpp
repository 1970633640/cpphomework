#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
int n,i;string a,b;
cin>>n;getline(cin,a);
for(i=0;i<n;i++)
{cout<<"case #" << i <<":" <<endl;
getline(cin,a);getline(cin,b);
transform(a.begin(), a.end(), a.begin(), ::toupper);
transform(b.begin(), b.end(), b.begin(), ::toupper);
if(b.find(a+" ")==0)cout<<b.find(a+" ")+1<<endl;
else if(b.find(" "+ a+" ")!=string::npos)cout<<b.find(" "+a+" ")+2<<endl;
else if(b.find(" "+ a)==b.length()-a.length()-1)cout<<b.length()-a.length()+1<<endl;
else cout<<"None"<<endl;
}
    return 0;
}
