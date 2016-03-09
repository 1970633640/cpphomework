#include <iostream>

using namespace std;

int main()
{
    long long int a,b,c;
    cin>>a>>b;
    while(b)
    {
        c=a%b;
        a=b;
        b=c;
    }
    cout << a << endl;
    return 0;
}
