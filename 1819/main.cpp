#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int x[10000]= {0};

int main()
{
    int n,t;
int i=0;
int j=1;
    char s;
    scanf("%d %d\n",&n,&t);
int temp=0;
    while(1)
    {
        s=getchar();
        if(s>='0' )
            {
            temp+=j*(s-'0');
            j*=10;
        }

        else if (s==' ')  {
            j=1;
x[temp]=1;
temp=0;
        }

        else if(s=='\n')    {x[temp]=1;break;}

    }

    j=1;
    t++;
    for(i=0; ; i++)
    {
        if(x[i]!=0)
        {
            printf("%d: %d\n",j,i);
            j++;
            if(j==t)break;
        }
    }

    return 0;
}
