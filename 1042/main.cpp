#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
  int n,i,x;
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
      scanf("%d",&x);
      printf("%d ",x/100);x-=(x/100)*100;
      printf("%d ",x/50);x-=(x/50)*50;
      printf("%d ",x/20);x-=(x/20)*20;
      printf("%d ",x/10);x-=(x/10)*10;
      printf("%d ",x/5);x-=(x/5)*5;
      printf("%d ",x/2);x-=(x/2)*2;
      printf("%d\n",x);
  }
    return 0;
}
