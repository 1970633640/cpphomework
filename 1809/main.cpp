#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
    int x[1000000];
int cmp ( const void *a , const void *b )
{ return *(int *)a - *(int *)b; }
int main()
{
    int key,i,n,j;
   scanf("%d",&n);
    scanf("%d",&j);
for(i=0;i<n;i++) scanf("%d",&x[i]);
qsort(x,n,sizeof(x[0]),cmp);

for(i=0;i<j-1;i++)cout<<x[i]<<" ";cout<<x[i]<<endl;
    return 0;
}
