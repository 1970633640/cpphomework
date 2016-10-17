#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int x[50];
int c[50];


int main()
{
    int n,i,temp,ans=0;
    scanf("%d\n",&n);
    for(i=0; i<n; i++)scanf("%d",&x[i]);
    if(n==1){cout<<"1";return 0;}
    else if(n==2 && x[0]!=x[1]){cout<<"2";return 0;}
    else if(n==2 && x[0]==x[1]){cout<<"1";return 0;}
    else {if(x[0]<x[1])c[0]=-1;else if(x[0]==x[1])c[0]=0;else c[0]=1;
    for(i=1;i<n;i++){ if(x[i]<x[i-1])c[i]=-1;else if(x[i]==x[i-1])c[i]=0;else c[i]=1; }
ans=0;temp=c[0];
for(i=1;i<n;i++)if((c[i]==1 || c[i]==-1) && c[i]!=temp ){ans++;temp=c[i];}
cout<<ans+1;
    }
    return 0;
}
