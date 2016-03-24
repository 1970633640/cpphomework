#include <iostream>
#include <string>
using namespace std;
int main()
{int i,n;string a,b;
 cin>>n;
getline(cin,a);
for(i=0;i<n;i++)
 {
getline(cin,a);getline(cin,b);
if(a.find(b)!=string::npos)cout<<"Yes"<<endl;
else cout<<"No"<<endl;
 }
    return 0;
}
