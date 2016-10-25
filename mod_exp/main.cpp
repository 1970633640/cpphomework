#include <iostream>

using namespace std;
int f(int a,int b,int c)
{
if(b==2)return ((a%c)*(a%c))%c;
else return ((  f(a,b-1,c) %c)*(a%c))%c;
}
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    cout<<f(a,b,c);
    return 0;
}
