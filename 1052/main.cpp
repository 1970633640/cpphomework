#include <iostream>
#include <stdio.h>
#include <string.h>
int w[100001],p[100001];
using namespace std;
int f(int num,int vmax)
{
    if(num==0 || vmax==0)return 0;
    else if (w[num]>vmax) return f(num-1,vmax) ;
    else return max(  f(num-1,vmax) ,f(num-1,vmax-w[num])+p[num]    );
}
int main()
{
   int ii,nn;
   cin>>nn;
   for(ii=0;ii<nn;ii++)
   {
       memset(w,0,100001);
       memset(p,0,100001);
       int num,vmax;
       cin>>num>>vmax;
       for(int i=1;i<=num;i++)
        scanf("%d %d",&w[i],&p[i]);
      cout<< f(num,vmax)<<endl;
   }
    return 0;
}
