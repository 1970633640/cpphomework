#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cctype>
#include <string>
#include <algorithm>
using namespace std;



int main()
{
    char w[10],t[10];
    string x;
    int n,i,j,ans[10],temp;
    scanf("%d",&n);
    getchar();
    for(i=0; i<n; i++)
    {
        ans[i]=-1;
        gets(w);
        strupr(w);
        getline(cin,x);
    transform(x.begin(), x.end(), x.begin(), ::toupper);
      //  printf("%s\n%s\n",x.c_str(),w);
          temp=x.find(w);
printf("%d\n",temp);
        if (temp==0 && (    x[strlen(w)]=='.' || x[strlen(w)]==' '  || x[strlen(w)]=='\0'     ))
        {
            ans[i]=0;
            continue;
        }


            if (temp>0 &&  (   (x[strlen(w)+temp]==' ')   ||(x[strlen(w)+temp]=='\0')||  (x[strlen(w)+temp]=='.')    ) && (x[temp-1]==' ')  )
            {
                ans[i]=temp;
            }

    }
    for(i=0; i<n; i++)
        {if(ans[i]!=-1)
            printf("case #%d:\n%d\n",i,ans[i]+1);
        else
            printf("case #%d:\nNone\n",i);}
    return 0;
}
