#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string a;
    string b;
    getline(cin,a) ;
    getline(cin,b) ;
    int x=0,i;
    for(i=0; i<=a.length()-2; i++)
    {
        if(i == a.find(b, i )  )//��λ��x��ʼ�����ַ�����eeefff���ڵ�ǰ�ַ����е�һ�γ��ֵ�λ��
            x++;
    }
    cout<<x<<endl;
    return 0;
}
