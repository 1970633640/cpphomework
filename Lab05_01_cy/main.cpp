#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

map<string,vector<int> > ans;

KeywordCounting(istream &sin,const vector<string> &key,int n)
{
    string str;
    while(sin>>str)
    {
        if(find(key.begin(),key.end(),str)!=key.end())
        {
            map<string,vector<int> >::iterator iter;
            iter=ans.find(str);
            if(iter!=ans.end())
                (iter->second).push_back(n);
            else
            {
                vector<int>num{n};
                ans.insert(pair<string,vector<int> >(str,num));
            }
        }
    }
}

int main(int argc,char *argv[])
{
    string line;
    vector<string> key;
    ifstream fin(argv[1],ios::in);
    ifstream fin2(argv[2],ios::in);
    ofstream fout(argv[3]);
    while(getline(fin,line))
        key.push_back(line);
    int n=1;
    while(getline(fin2,line))
    {
        istringstream sin(line);
        KeywordCounting(sin,key,n);
        n++;
    }
    fin.close();fin2.close();
    map<string,vector<int>>::iterator iter;
    vector<int>::iterator iternum;
    for(iter=ans.begin();iter!=ans.end();iter++)
    {
        fout<<iter->first<<" : { ";
        for(iternum=(iter->second).begin();iternum!=(iter->second).end();iternum++)
        {
            if(iternum==(iter->second).begin()) fout<<*iternum;
            else fout<<","<<*iternum;
        }
        fout<<" }"<<endl;
    }
    return 0;
}
