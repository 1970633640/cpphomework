#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n ;
    if(n%5==0 && n%3==0)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}
