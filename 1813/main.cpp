#include <iostream>
#include <string>
using namespace std;
string a,b;
void f(string x)
{
    if(x.length()==1)
    {
        cout<<x;
        return;
    }
    else for(int i=0; i<a.length(); i++)
        {
            int c=x.find(a[i]);
            if(c!=string::npos)
            {
                f(x.substr(0,c));
                f(x.substr(c+1));
                cout<<x[c];
                break;
            }
        }
}
int main()
{
    cin>>a>>b;
    f(b);
    return 0;
}
