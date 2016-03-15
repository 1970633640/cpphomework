#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(int argc,char *argv[])

{
    int i,j,k,x=0;char a[10000]={'\0'};
char b[10000]={'\0'};
     ifstream fin;
     ofstream fout;

fout.open(argv[2]);            //path of the output file in the command
fin.open(argv[1]);              //path of the input file in the command
i=0;
while(i<10000)
{
fin.get(a[i]);                       //one word per the loop
i++;
}
k=0;
int flag=1;    //   0 stands for quotation mark, 1 is the normal state, 2 is the // note  3 is the /* */ note
for(j=0;j<i;j++)
{
    if (a[j]=='\\')
    { j++;}
else if(flag==1 && a[j]=='\"'){flag=0;}                         //find the keyword(s) to change the states
else if(flag==1 && a[j]=='\''){flag=0;}
else if(flag==0 && a[j]=='\"'){flag=1;}
else if(flag==0 && a[j]=='\''){flag=1;}
else if(flag==1 && a[j]=='/' && a[j+1] == '/') {flag=2;j=j+1;}
else if(flag==2 && a[j]=='\n'){flag=1;}
else if(flag==1 && a[j]=='/' && a[j+1] == '*') {flag=3;}
else if(flag==3 && a[j]=='*' && a[j+1] == '/') {flag=1;j=j+2;}
if(flag==1 || flag==0) {b[k]=a[j];k++;}
}
for(j=0;j<i && b[j]!='\0';j++)fout <<b[j];                            //output to the file
fin.close();
fout.close();
return 0;
}
