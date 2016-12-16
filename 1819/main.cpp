#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int x[4194306] = { 0 }; //初始化下标数组
int main()
{
    int i,j,p,n, k;
    scanf("%d%d\n", &n, &k);
    char c;
    for (i = 0; i<n; i++) //读n个数字
    {

        p = 0;

while (1)
		{c = getchar();
		if(c==' '||c=='\n')break; //使用char快速读取多个空格分隔数字
			p = (c - '0') + 10 * p;
		}
		x[p]=1;
    }
    j = 1;
    for (i = 0; i<4194306; i++)
    {
        if (x[i] == 1)
        {
            printf("%d: %d\n", j, i);
            j++;
        }
        if (j>k)
            break;
    }
    return 0;
}
