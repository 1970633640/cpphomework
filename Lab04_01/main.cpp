#include <iostream>
#include <stack>
#include <cstdlib>
#include <ctime>
using namespace std;
void display(stack<int> s)
{ while (!s.empty()) cout<<s.top()<<endl,s.pop();
  cout<<endl;
}
void StackSort(stack<int>& s)
{


  stack<int> x;
int flag,a,b,temp;
while(1)
{
    flag=0;
b=s.top();
s.pop();
while(!s.empty())
{
a=s.top();
s.pop();
if(a>b){temp=a;a=b;b=temp;}
else if(a<b)flag=1;
x.push(a);
}
x.push(b);
while(!x.empty())
{
    temp=x.top();
    x.pop();
    s.push(temp);
}

    if(flag==0)break;
}


}


int main(int argc,char**argv)
{ const int n{20};
  srand((unsigned)time(0));
  stack<int> s;
  for (int i{0};i<n;i++) s.push(rand()%100);
  cout<<"Before sorting:"<<endl<<endl;  display(s);
  cout<<"After sorting:"<<endl; StackSort(s); display(s);
  return 0;
}
