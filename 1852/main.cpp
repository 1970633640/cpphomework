#include <iostream>
    int x;
using namespace std;
void f(int a,int b,int c,int d)
{
    int xx=a+c;
    int y=b+d;
    if(b+d<=x)
    {
        f(a,b,xx,y);
        cout<< xx<<"/"<<y<<endl;
        f(xx,y,c,d);
    }
}
int main()
{

    cin>>x;cout<<"0/1"<<endl;
    f(0,1,1,1);cout<<"1/1"<<endl;
    return 0;
}
