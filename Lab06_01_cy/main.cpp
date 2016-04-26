#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <fstream>

using namespace std;
map<string,vector<int>>ans;
void KeywordsCounting(string line, vector<string> &key, int n)
{
    vector<string>::iterator iter;
    for(iter=key.begin();iter!=key.end();iter++)
    {
        if(line.find(*iter)!=string::npos)
        {
            map<string,vector<int>>::iterator iternum;
            iternum=ans.find(*iter);
            (iternum->second).push_back(n);
        }
    }
}

bool compare(map<string,vector<int>>::iterator a,map<string,vector<int>>::iterator b)
{
    return (a->second).size() > (b->second).size();
}

int main(int argc,char *argv[])
{
    ifstream fin(argv[1]);
    ifstream fin2(argv[2]);
    ofstream fout(argv[3]);
    string line;
    vector<string>key;
    while(getline(fin,line))
    {
        key.push_back(line);
        vector<int>num;
        ans.insert(pair<string,vector<int>>(line,num));
    }
    int n=1;
    while(getline(fin2,line))
        KeywordsCounting(line,key,n++);
    fin.close();
    fin2.close();
    vector<map<string,vector<int>>::iterator> keyword;
    map<string,vector<int>>::iterator iter1;
    for(iter1=ans.begin();iter1!=ans.end();iter1++)
        keyword.push_back(iter1);
    sort(keyword.begin(),keyword.end(),compare);
    vector<map<string,vector<int>>::iterator>::iterator iter;
    vector<int>::iterator iternum;
    for(iter=keyword.begin();iter!=keyword.end();iter++)
    {
        fout<<(*iter)->first<<"("<<((*iter)->second).size()<<")"<<" : { ";
        for(iternum=((*iter)->second).begin();iternum!=((*iter)->second).end();iternum++)
        {
            if(iternum==((*iter)->second).begin()) fout<<*iternum;
            else fout<<","<<*iternum;
        }
        fout<<" }"<<endl;
    }
    fout.close();
    return 0;
}
