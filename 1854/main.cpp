#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n,i,j,l,r;
    int ans1,ans2,ans=0;
    char L,R;
    string x,xx;
    scanf("%d\n",&n);
    cin>>xx;
    for(i=0; i<=n-1; i++)
    {x=xx;
        L='w';
        R='w';
        l=i;
        r=(i+1)%n;
        ans1=0;
        ans2=0;

        while(1)
        {
            ans1++;
            if(L=='w' && x[l]!='w'  )L=x[l];
            x[l]='n';
            if(l==0)l=n-1;
            else l--;
            if( (L!='w' && x[l]!='w' && x[l]!=L)||x[l]=='n' )break;
        }
        if(x[r]=='n')goto aaa;
        while(1)
        {
            ans2++;
            if(R=='w' && x[r]!='w' )R=x[r];
            x[r]='n';
            r=(r+1)%n;
            if( (R!='w'  && x[r]!='w' && x[r]!=R) ||x[r]=='n' )break;
        }

aaa:

        if(ans1+ans2>ans)ans=ans1+ans2;

    }
    printf("%d",ans);

    return 0;
}
