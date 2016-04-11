#include <iostream>

using namespace std;

int main()
{
    int i,j,k,c,n,x[20],ans,flag;
    cin>>n;
    for(i=0;i<n;i++)
    {cout<<"case #"<<i<<":"<<endl;
cin>>c;
for(j=0;j<c;j++)
{
    cin>>x[j];
}
if(x[0]==-1){x[0]=x[3]-x[2]-x[1];ans=x[0];}
else if(x[1]==-1){x[1]=x[3]-x[2]-x[0];ans=x[1];}
else if(x[2]==-1){x[2]=x[3]-x[1]-x[0];ans=x[2];}
else {for(k=3;k<c;k++)if(x[k]==-1){x[k]=x[k-1]+x[k-2]+x[k-3];ans=x[k];break;}         }
flag=1;
for(j=3;j<c;j++)if(x[j]!=x[j-3]+x[j-2]+x[j-1] ||x[j]<=0||x[j-3]<=0||x[j-2]<=0||x[j-1]<=0){flag=0;break;}
if(flag==1)cout<<ans<<endl;
else cout<<-1<<endl;
    }
    return 0;
}
