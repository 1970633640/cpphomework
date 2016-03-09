#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
bool cmp(const int a,const int b)
{
    return a>b;
}
int main()
{
    char way,c;
    cin>>way;
    int count=0,i=0,j=0,t;
    int x[100],y[100]= {0};
    while(1)
    {
        cin>>t;
        x[count]=t;
        count++;
        c=getchar();
        if(c=='\n') break;
    }
    if (way=='A')sort(&x[0],&x[count]);
    else sort(&x[0],&x[count],cmp);
    unique_copy(&x[0],&x[count],y);
    cout<<y[0];
    i=1;
    while(y[i]!=0 )
    {
        cout<<' '<<y[i];
        i++;
    }

    return 0;
}
