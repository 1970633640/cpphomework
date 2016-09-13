#include <iostream>

using namespace std;

int main()
{
    int a,x[1026];
    int key;
    cin>>a;
    int i,j;
    for(i=0; i<a; i++)cin>>x[i];
    a--;
    int d;
    cin>>d;
    for(i=0; i<d; i++)
    {
        cin>>key;
        key--;
        if(key<=a && key>=0){cout<<x[key]<<endl;

        for(j=key; j<a; j++)x[j]=x[j+1];
        a--;

        }
        else cout<<"-1"<<endl;


    }
}
