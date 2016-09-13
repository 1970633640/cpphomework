#include <iostream>
#include <stack>
using namespace std;

int main()
{
int i,j,k,x;
cin>>x;
for(i=0;i<x;i++)
{int flag=1;
    int a;string b;
    cin>>a;cin>>b;
    stack <int> one;
    stack <int> two;
    for(j=0;j<a;j++)one.push(a-j);
    for(k=0;k<a;k++)
    {//cout <<"--" <<(int)(b[k]-'0')<<"--\n";
        if(one.empty()==false && (int)(b[k]-'0') ==one.top()  )one.pop();
        else if (two.empty()==false && (int)(b[k]-'0') ==two.top() )two.pop();
        else if (one.empty()==false)  {two.push(one.top());one.pop();k--;}
        else flag=0;


    }
if(flag==1)cout<<"yes\n"; else cout<<"no\n";
}
}
