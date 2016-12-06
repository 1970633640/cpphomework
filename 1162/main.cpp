#include <stdlib.h>
#include <iostream>
#include <stdio.h>
//#include <time.h>
//#include <windows.h>
using namespace std;
typedef struct pos
{
    int x;
    int y;
    int face;//↑1    ↓3   ←4   →2
}pos;
int main()
{
    pos c,m;char t;int n;
    bool x[12][12]; //false无障碍
   aaa:
    scanf("%d\n",&n);
    while(n--)
    {


    for(int i=0;i<=11;i++)
        for(int j=0;j<=11;j++)
        x[i][j]=true;
    for(int i=1;i<=10;i++){
        for(int j=1;j<=10;j++)
    {
        t=getchar();
        if(t!='*')x[i][j]=false;
         if(t=='M'){m.x=j;m.y=i;}
         if(t=='C'){c.x=j;c.y=i;}
    }t=getchar();}
  //   for(int i=0;i<=11;i++){
     //   for(int j=0;j<=11;j++)printf("%d",x[i][j]);printf("\n");}
   //  printf("%d %d %d %d\n",c.x,c.y,m.x,m.y);
      //    for(int i=0;i<=11;i++){
     //   for(int j=0;j<=11;j++){if(i==m.y && j==m.x)printf("M"); else if(i==c.y && j==c.x)printf("C");else if(x[i][j]==true)printf("1"); else printf(" ");}printf("\n");}
     c.face=1;m.face=1;
int sum=0;
while(1)
{
if(c.x==m.x && c.y==m.y)break;
else
{
    if(c.face==1 && !x[c.y-1][c.x])--c.y;
    else if(c.face==1 && x[c.y-1][c.x])c.face=2;
    else  if(c.face==2 && !x[c.y][c.x+1])++c.x;
    else if(c.face==2 && x[c.y][c.x+1])c.face=3;
       else  if(c.face==3 && !x[c.y+1][c.x])++c.y;
    else if(c.face==3 && x[c.y+1][c.x])c.face=4;
       else  if(c.face==4 && !x[c.y][c.x-1])--c.x;
    else if(c.face==4 && x[c.y][c.x-1])c.face=1;

        if(m.face==1 && !x[m.y-1][m.x])--m.y;
    else if(m.face==1 && x[m.y-1][m.x])m.face=2;
    else  if(m.face==2 && !x[m.y][m.x+1])++m.x;
    else if(m.face==2 && x[m.y][m.x+1])m.face=3;
       else  if(m.face==3 && !x[m.y+1][m.x])++m.y;
    else if(m.face==3 && x[m.y+1][m.x])m.face=4;
       else  if(m.face==4 && !x[m.y][m.x-1])--m.x;
    else if(m.face==4 && x[m.y][m.x-1])m.face=1;

    ++sum;
    if(sum>1000){printf("-1\n");goto aaa;}
}

//Sleep(100);
 //system("Cls");
   //  for(int i=0;i<=11;i++){
     //   for(int j=0;j<=11;j++){if(i==m.y && j==m.x)printf("M"); else if(i==c.y && j==c.x)printf("C");else if(x[i][j]==true)printf("1"); else printf(" ");}printf("\n");}
//printf("%d\n",sum);
}
printf("%d\n",sum);}
    return 0;
}
