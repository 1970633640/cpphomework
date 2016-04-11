#include <iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
double expr(){
    char a[10];
    double f1, f2;
scanf("%s",a);
    switch(a[0]){
       case'+': {f1= expr( ); f2 = expr( ); return f1 + f2;}
       case'-': {f1= expr( ); f2 = expr( ); return f1 - f2;}
       case'*': {f1= expr( ); f2 = expr( ); return f1 * f2;}
       case'/': {f1= expr( ); f2 = expr( ); return f1 / f2;}
       default: return atof(a);
   }
}
int main()
{int n,i;
cin>>n;
string a;
for(i=0;i<n;i++){
  cout<<  "case #" << i<< ":"<<endl;
printf("%f\n", expr());
}
    return 0;
}
