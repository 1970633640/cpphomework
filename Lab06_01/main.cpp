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
void f(string line, vector<string> &key)
{
    string w;
    vector <string> word;

    vector<string>::iterator temp;
    map<string,vector<int> >::iterator iter;
    for(temp=key.begin() ; temp!=key.end(); temp++)
    {
     //   if((find(word.begin(),word.end(),*temp)) !=word.end() )
     if (line.find(*temp)!=string::npos)
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

bool cmp(  map<string,vector<int> >::iterator  a,  map<string,vector<int> >::iterator  b)
{
return (a->second).size() > (b->second).size();
//return (a->second).size()> (b->second).size();
}


int main(int argc,char* argv[])
{
string s,x;
int i;
//ifstream fin("text.txt",ios::in);
//ifstream fin2("keywords.txt",ios::in);
//ofstream fout("result.txt");


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
        f(s,key);
    }
    fin.close();
    fin2.close();
    map<string,vector<int> >::iterator iter2;
    vector<int>::iterator x2;
        vector < map<string,vector<int> >::iterator > iter;
                vector < map<string,vector<int> >::iterator > ::iterator iter1;
          for(iter2=ans.begin(); iter2!=ans.end(); iter2++)
            {iter.push_back(iter2) ;}
sort(iter.begin(),iter.end(),cmp);

    for(iter1=iter.begin(); iter1!=iter.end(); iter1++)
    {
        fout<<(*iter1)->first<<"("<<(  (*iter1)->second).size() <<")"<<" : { ";
        for(x2=( (*iter1)->second).begin(); x2!=(  (*iter1)->second).end(); x2++)
            fout<<*x2<<" ";
        fout<<"}"<<endl;
    }

    fout.close();
    return 0;
}
