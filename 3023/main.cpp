#include <iostream>
#include <string>
#include<algorithm>
using namespace std;
void f(string x,string ans)
{
cout <<ans<<x.substr(0,1)<<endl;
ans=ans+x.substr(0,1);
if(x.length()>1)f(x.substr(1),ans);
if(x.length()>1 && ans.length()>=1)f(x.substr(1),ans.substr(0,ans.length()-1));

}
int main()
{
    int n,i,k;
    string s,x;

    cin>>n;
    for(i=0;i<n;i++)
    {
cin>>s;
x.resize(s.size());
sort(s.begin(),s.end());
x.resize(unique_copy(s.begin(),s.end(),x.begin()) -x.begin()  );
cout<<"case #" << i << ":" <<endl;
f(x,"");
    }



    return 0;
}
