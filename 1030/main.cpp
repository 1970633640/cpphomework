#include <iostream>

using namespace std;


int main()
{
   int c[51],i,x;
   c[0]=1;c[1]=1;c[2]=1;c[3]=1;
 for(i=4;i<51;i++) c[i]=c[i-1]+c[i-3];
while(cin>>x){if(x==0)break;cout<<c[x]<<endl; }
return 0;
}
