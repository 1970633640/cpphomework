#include <iostream>

using namespace std;
long long int a[102][102];
long long int f(int  n, int m)
{
if(m == 1 || n == 0) return 1;
if(m > n) return f(n, n);

return a[n][m]=f(n, m-1) + f(n-m, m);
}

int main()
{
    int n;
    long long int  ans[109][109];   //ans[ball][box]
   ans[0][1]=1;
   int ball=1,box=0;
    while(1){
        box=box+1;
        if (box==108){ball++;box=1;}
        //   if(box>ball)box=ball;
if (ball==108)break;
       ans[ball][box]=ans[ball][box-1]+ans[ball-box][box];

    //    cout<<ball<<"  "<<box<<endl;
    }

    while(cin>>n)
        cout<<ans[n+1][n+1]<<endl;
    return 0;
}
