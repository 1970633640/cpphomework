#include <iostream>
#include <string>
#include <stdio.h>
#include <cctype>
using namespace std;

int main()
{
    string str,str1;
    int n,i,j,l,sum,num,T,t;
    cin>>T;                                                     //����������
    getchar();
    for(t=0; t<T; t++)
    {
        cout<<"case #"<<t<<':'<<endl;                           //�����ʽ���
        getline(cin,str);
        getline(cin,str1);
        n=str.length();
        num=0;
        for(i=0; i<n; i++)
        {
            if(!isalnum(str[i])) continue;
            else
            {
                for(j=i; isalnum(str[j]); j++)                      //��ĸ�ַ����ָ�Ϊ���ַ���������Ϊ��¼����
                {}
                for(l=0,sum=0; l<j-i; l++)
                {
                    if(str[l+i]==str1[l]) sum++;                    //�ж��Ƿ������ַ����Ƿ���ͬ
                }
                if(sum==str1.length()&&j-i==str1.length()) num++;
                i=j;
            }
        }
        cout<<num<<endl;                                            //������ֵĴ���
    }
    return 0;
}
