#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int i,n;
    char x[2001];
    cin>>n;
    for(i=0; i<n; i++)cin>>x[i];
    int l=0,r=n-1,c=0,flag;
    while(l<=r)
    {
        flag=0;
        for(i=0; i<r-l; i++)
            if(x[l+i]<x[r-i])
            {
                flag=1;
                c++;
                break;
            }
            else if(x[l+i]>x[r-i])
            {
                flag=0;
                c++;
                break;
            }
        if(flag==1)
        {
            printf("%c",x[l]);
            l++;
        }
        else
        {
            printf("%c",x[r]);
            r--;
        }
        if(c%80==0)printf("\n");
    }
    return 0;
}
