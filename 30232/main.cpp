#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

void comb(string s,string t,set<string>&word)
{
    word.insert(t+s.substr(0,1));
    t=t+s.substr(0,1);
    if(s.length()>1) comb(s.substr(1),t,word);
    if(s.length()>1&&t.length()>=1) comb(s.substr(1),t.substr(0,t.length()-1),word);
}

int main()
{
	int T, t;
	cin >> T;
			string s2;
	for (t = 1; t <= T; t++)
	{s2=s2+(char)(t);}

set<string>word;
        comb(s2,"",word);
        cout<<"case #"<<t<<":"<<endl;
        set<string>::iterator iter1;
        cout<<"{\n空集\n";
        for(iter1=word.begin();iter1!=word.end();iter1++)
            {string x=(*iter1);
            for(int m=0;m<x.length();m++)cout<<(int)x[m]<<" ";
            cout<<endl;
            }
cout<<"}"<<endl;
	return 0;
}
