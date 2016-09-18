#include <iostream>

using namespace std;

int main()
{
   long long int x,x1,x2;
   int cows,cow[50000],n,i;
   cin>>cows>>n;
for(i=0;i<cows;i++)cin>>cow[i];
   x1=0; x2=1;
   for(i=1;i<n;i++){x=(2*x1+x2)%987654321;x1=x2;x2=x;}//cout<<x<<"-";
   if (n % 2 !=0){long long int sum=0;for(i=0;i<cows;i++)sum+=(x*cow[i]);
   for(i=0;i<cows;i++)cout<<(sum-cow[i])%987654321<<endl;
   }
   else{
    long long int sum=0;for(i=0;i<cows;i++)sum+=(x*cow[i]);
   for(i=0;i<cows;i++)cout<<(sum+cow[i])%987654321<<endl;

   }
    return 0;
}
