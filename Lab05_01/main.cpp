#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
map<string,vector<int> > ans;
vector <string> key;
int n;
void f(istream &line, vector<string> &key)
{
    string w;
    vector <string> word;
    while(line>>w)word.push_back(w);
    vector<string>::iterator temp;
    map<string,vector<int> >::iterator iter;
    for(temp=key.begin() ; temp!=key.end(); temp++)
    {
        if((find(word.begin(),word.end(),*temp)) !=word.end() )
        {
            iter=ans.find(*temp);
            if(iter!=ans.end())
                (iter->second).push_back(n);
            else
            {
                vector<int> ivec(1,n); ;
                ans.insert(pair<string,vector<int> >(*temp,ivec));
            }
        }
    }
}
int main(int argc,char* argv[])
{
string s,x;
ifstream fin(argv[1],ios::in);
ifstream fin2(argv[2],ios::in);
ofstream fout(argv[3]);
    while( getline(fin2,s) )
    {
        key.push_back(s);
    }
    n=0;
    while(   getline(fin,s)   )
    {
        n++;
        istringstream line(s);
        f(line,key);
    }
    fin.close();
    fin2.close();

    vector<int>::iterator x2;
    map<string,vector<int> >::iterator iter2;
    for(iter2=ans.begin(); iter2!=ans.end(); iter2++)
    {
        fout<<iter2->first<<" : { ";
        for(x2=(iter2->second).begin(); x2!=(iter2->second).end(); x2++)
            fout<<*x2<<" ";
        fout<<"}\n";
    }

    fout.close();
    return 0;
}
