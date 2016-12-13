#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
int x[1000000];
int cmp ( const void *a, const void *b )
{
    return *(int *)a - *(int *)b; //快速排序比较，从小到大排序
}
int main()
{
    int key,i,n,j;
    scanf("%d",&n);
    scanf("%d",&j);
    for(i=0; i<n; i++) scanf("%d",&x[i]); //输入数据
    qsort(x,n,sizeof(x[0]),cmp); //调用快速排序

    for(i=0; i<j-1; i++)cout<<x[i]<<" "; //输出后面有空格的内容
    cout<<x[i]<<endl; //输出最后一项，后面无空格
    return 0;
}
