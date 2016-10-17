#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int cmp ( const void *a, const void *b )
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int n,ii,i,xx,x[10001];
    long long int ans;
    scanf("%d",&n);
    for(ii=0; ii<n; ii++)
    {
        scanf("%d",&xx);
        for(i=0; i<xx; i++)scanf("%d",&x[i]);
        qsort(x,xx,sizeof(x[0]),cmp);
        ans=0;
        for(i=0; i<xx; i++)ans+=(xx-i-1)*x[i];
        printf("%I64d",ans);
    }
    return 0;
}
