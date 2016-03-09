#include <iostream>

using namespace std;

int main()
{
    int i,j,flag[201]={0};
    flag[1]=0;flag[2]=0;
    for(i=2;i<201;i++)
    {
        if(flag[i]==0)
            for(j=2;j<200/i;j++)flag[j*i]=1;
    }
        for(i=100;i<200;i++)if(flag[i]==0)cout<<i<<" ";
        return 0;
}
