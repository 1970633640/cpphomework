#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void quicksort(int ans[],int left,int right)
{
    if (left>=right)return ;
    int l=left,r=right,key=ans[left];
    while(l<r)
    {
        while(l<r && ans[r]>=key)r--;    //跳过不需要交换位置的数字
        ans[l]=ans[r];   //交换且关键的数字被覆盖了

        while(l<r && ans[l]<=key)l++;
        ans[r]=ans[l];   //交换且代表关键数字的错误数字回来了
    }
    ans[l]=key;  //错误数字换成关键数字
    quicksort(ans,left,l-1);   //递归
    quicksort(ans,l+1,right);

}

int main()
{
    int i,x,key;
    cin>>x;
    int   *ans=new   int[x];
    for(i=0; i<x; i++)
    {
        cin>>key;
        ans[i]=key;
    }
    quicksort(ans,0,x-1);
    for(i=0; i<x-1; i++)cout<<ans[i]<<" ";
    cout<<ans[i];
    delete []ans;
    return 0;
}
