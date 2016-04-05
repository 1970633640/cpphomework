#include <iostream>
#include <string>
#include <stdio.h>
#include <sstream>

using namespace std;

int main()
{
    int T,t;
    cin>>T;
    for(t=0;t<T;t++)
    {
        int str_len,line_len,start,i,j,words_len,words_count,p,l,space;
        string s;
        cin>>line_len;
        getchar();
        getline(cin,s);
        cout<<"case #"<<t<<":"<<endl;
        istringstream sin(s);
        string str;
        sin>>str;
        i=s.find(str);
        str_len=s.length();
        while(i<str_len)
        {
        start=i;
        words_len=0,words_count=0;
        for(;words_len+words_count<=line_len&&i<str_len;)
        {
            for(l=0,p=i;s[p]!=' '&&p<str_len;p++,l++);


if(words_len+words_count+l<=line_len)
            {
                words_len+=l;words_count++;
                for(i=p;s[i]==' ';i++);
            }
            else break;
        }
        space=line_len-words_len;
        j=start;
        words_count--;
        while(j<i)
        {
        while(s[j]!=' '&&j<str_len) cout<<(s[j++]);
        while(s[j]==' '&&j<str_len) j++;
        if(i==str_len&&words_count)
            cout<<" ";
        else
        {   for(p=0;words_count&&p<space/words_count;p++)
                 cout<<" ";
            space-=p;
        }
            words_count--;
        }    cout<<endl;
        }
    }
    return 0;
}
