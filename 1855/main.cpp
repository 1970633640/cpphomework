#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
typedef struct x
{
    int s;
    int x;
} x;

int cmp( const void *a,const void *b)

{
    return (*(x *)a).x < (*(x *)b).x ? 1 : -1;
}

int main()
{
    int n,i,S,X;
    x x[10000];
    scanf("%d",&n);
    for(i=0; i<n; i++)scanf("%d %d",&(x[i].s),&(x[i].x));
    scanf("%d %d",&S,&X);
    for(i=0; i<n; i++)x[i].s=S-x[i].s;
    qsort(x,n,sizeof(x[0]),cmp);
    int key,ans=0;
    while(X<S)
    {
        key=-1;
        for(int k=0; k<n; k++)if( x[k].s<=X && x[k].x>0)
            {
                key=k;
                break;
            }
        if(key==-1)
        {
            printf("-1");
            return 0;
        }
        else
        {
            X=X+x[key].x;
            ans++;
            x[key].x=0;
        }
    }
    printf("%d",ans);
    return 0;
}
