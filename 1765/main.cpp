#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
typedef struct x
{
    short w;
    short h;
} xx;

int cmp( const void *a,const void *b)
{
    if ((*(xx *)b).w != (*(xx *)a).w )
        return (*(xx *)b).w - (*(xx *)a).w ;
    else return (*(xx *)a).h - (*(xx *)b).h ;
}

int main()
{
    int nn,ii,n,i;
    xx x[20001];
    scanf("%d",&nn);
    for(ii=0; ii<nn; ii++)
    {
        scanf("%d",&n);
        for(i=0; i<n; i++)scanf("%d%d",&x[i].w,&x[i].h);
        qsort(x,n,sizeof(x[0]),cmp);
     //   for(i=0; i<n; i++)printf("%d %d\n",x[i].w,x[i].h);  排序后
        int ans=1;
        xx dp[20001];
        dp[1]=x[0];
        for(i=1; i<n; i++)
        {
            int l=0,r=ans;
            while(l+1<r)
            {
                int mid=l+(r-l)/2;
                if(x[i].w  <dp[mid].w && x[i].h<dp[mid].h)r=mid;
                else l=mid;
            }
            if(x[i].w  <dp[r].w && x[i].h<dp[r].h)dp[r]=x[i];
            else
            {
                ans++;
                dp[ans]=x[i];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
