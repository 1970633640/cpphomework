#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
using namespace std;

int main()
{
    char c[100];
    ifstream fin;
    scanf("%s",c);
    fin.open(c);

    string a;
    string b;
    getline(fin,a) ;
    getline(fin,b) ;

    int x=0,i;
    for(i=0; i<=a.length()-2; i++)
    {
        if(i == a.find(b, i )  )//��λ��x��ʼ�����ַ�����eeefff���ڵ�ǰ�ַ����е�һ�γ��ֵ�λ��
            x++;
    }
    cout<<x<<endl;
    return 0;
}
