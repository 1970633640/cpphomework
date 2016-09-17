#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
float x[100000],y[100000];
int main()
{
   int n,i,j;
while(scanf("%d",&n) && n!=0){
           float ans=9999999.9,temp;
for(i=0;i<n;i++)
{
    scanf("%f %f",&x[i],&y[i]);
}
for(i=0;i<n-1;i++)
{
    for(j=i;j<n-1;j++)
    {temp= fabsf( powf(x[j]-x[j+1],2)+powf(y[j]-y[j+1],2));
        if(   temp <ans )ans=temp;
    }
}
printf("%.2f\n",sqrt(ans)/2.0);
}
return 0;
}
