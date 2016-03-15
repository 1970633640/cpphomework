#include <iostream>
#include  <map>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
    string a;
    int c;
    char b[10];
    int i,k,n,x;
    map  <char,int> number;   //transform letters to numbers
    map  <int,int> cc;    //count of the tel numbers

    number.insert(pair<char,int>('A',2));
    number.insert(pair<char,int>('D',3));
    number.insert(pair<char,int>('G',4));
    number.insert(pair<char,int>('J',5));
    number.insert(pair<char,int>('M',6));
    number.insert(pair<char,int>('P',7));
    number.insert(pair<char,int>('T',8));
    number.insert(pair<char,int>('W',9));
    number.insert(pair<char,int>('Z'+1,10));   //use upper_bound so the number is 1 bigger than the correct number
    map<char,int>::iterator iter;
    map<int,int>::iterator iter2;
    cin>>n;
    for(x=0; x<n; x++)
    {
        cin>>a;
        k=0;
        for(i=0; i<a.length(); i++)             //the maximum length of the input string is 80
        {
            if(a[i]>='A' && a[i]<='Z')
            {
                iter=number.upper_bound(a[i]);               //transform a letter into a number
                b[k]=(iter->second)+'0'-1;
                k++;
            }
            if(a[i]>='0' && a[i]<='9')
            {
                b[k]=a[i];                                                 //keep numbers
                k++;
            }                                                                //ignore other characters
        }
        b[k]='\0';
       c=atoi(b);
        iter2=cc.find(c);
        if(iter2==cc.end())
            cc.insert(pair<int,int>(c,1));                   //a new number
        else
            iter2->second=iter2->second+1;            //an already existing number
    }
    for(iter2=cc.begin(); iter2!=cc.end(); iter2++)
    {
       printf("%04d-%04d %d\n",(iter2->first) / 10000,(iter2->first)%10000,iter2->second);   //format it
    }
    return 0;
}
