#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
using namespace std;

int main(int argc,char *argv[])
{
    ifstream fin;
    fin.open(argv[1]);
    string a;
    string b;
    getline(fin,a) ;
    getline(fin,b) ;
    int x=0,i;
    for(i=0; i<=a.length()-2; i++)
    {
        if(i == a.find(b, i )  )
            x++;
    }
    cout<<x<<endl;

    cout<<"Process returned 0 (0x0)   execution time : 0.000 s\nPress any key to continue."<<endl;
    char cc;
    cc=getch();
    return 0;

}
