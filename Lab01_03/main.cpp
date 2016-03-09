#include <iostream>
#include <string>
#include <stdio.h>
#include <cctype>
using namespace std;

int main()
{
    string str,str1;
    int n,i,j,l,sum,num,T,t;
    cin>>T;                                                     //输入问题数
    getchar();
    for(t=0; t<T; t++)
    {
        cout<<"case #"<<t<<':'<<endl;                           //问题格式输出
        getline(cin,str);
        getline(cin,str1);
        n=str.length();
        num=0;
        for(i=0; i<n; i++)
        {
            if(!isalnum(str[i])) continue;
            else
            {
                for(j=i; isalnum(str[j]); j++)                      //将母字符串分割为子字符串，方法为记录坐标
                {}
                for(l=0,sum=0; l<j-i; l++)
                {
                    if(str[l+i]==str1[l]) sum++;                    //判定是否两个字符串是否相同
                }
                if(sum==str1.length()&&j-i==str1.length()) num++;
                i=j;
            }
        }
        cout<<num<<endl;                                            //输出出现的次数
    }
    return 0;
}
